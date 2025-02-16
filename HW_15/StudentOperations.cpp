
#include <algorithm>
#include <vector>
#include <string>

struct Student { std::string Name; double Marks[5]; };

Student* FindaStudent(const std::string& nameofastudent, Student students[], int size)
{
	std::string name = nameofastudent;

	name[0] = toupper(name[0]);

	for (int i = 1; i < name.length(); i++)
	{
		name[i] = tolower(name[i]);
	}

	for (int i = 0; i < size; i++)
	{
		if (students[i].Name == name)
		{
			return &students[i];
		}
	}

	return nullptr;
};

void PrintStudentsList(Student students[], int size)
{

	for (int i = 0; i < size; i++)
	{
		std::cout << students[i].Name << std::endl;
	};
};

double getAverageMark(const Student& student)
{
	double sum = 0;

	for (double mark : student.Marks)
	{
		sum += mark;
	};

	return sum / 5;

};

Student* getBestStudent(Student* students, unsigned size)
{
	if (size == 0) return nullptr;

	Student* best = &students[0];
	double bestAvg = getAverageMark(students[0]);

	for (unsigned i = 1; i < size; i++)
	{
		double avg = getAverageMark(students[i]);

		if (avg > bestAvg)
		{
			best = &students[i];
			bestAvg = avg;
		};
	};

	return best;

};

int countAboveAverage(Student* students, int size, double Treshold)
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (getAverageMark(students[i]) > Treshold)
		{
			count++;
		};
	}

	return count;
};

void getBestStudents(Student* inStudents, int inSize, Student* outStudents, int& outSize, unsigned percent)
{
	std::vector<Student> sortedStudents(inStudents, inStudents + inSize);

	std::sort(sortedStudents.begin(), sortedStudents.end(),
		[](const Student& a, const Student& b)
		{return getAverageMark(a) > getAverageMark(b); });

	outSize = (percent * inSize + 99) / 100;

	for (int i = 0; i < outSize; i++)
	{
		outStudents[i] = sortedStudents[i];
	}
};

void sortStudentsByAverage(Student* students, unsigned size)
{
	std::sort(students, students + size, [](const Student& a, const Student& b) {return getAverageMark(a) > getAverageMark(b); });
};
