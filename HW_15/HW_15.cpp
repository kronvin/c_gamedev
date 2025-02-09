//HW_15

#include <iostream>
#include "StudentOperations.h"



int main()
{
	const int SizeofList = 6;

	Student students[SizeofList] = {
	{"Frank", {67, 55, 60, 65, 80}},
	{"Lisa", {75, 76, 74, 77, 75}},
	{"Sam", {90, 100, 99, 95, 94}},
	{"Alex", {65, 55, 60, 58, 53}},
	{"Bill", {85, 80, 77, 81, 79}},
	{"Sara", {80, 60, 100, 95, 60}}
	};

	std::cout << "List of current students: \n";

	PrintStudentsList(students, SizeofList);

	std::cout << std::endl << std::endl;

	while (true)
	{

		std::cout << "What do you want to do? \n"
			<< "1 - Find the best student \n"
			<< "2 - Find students with marks higher than selected treshold \n"
			<< "3 - Get percentage of the most succesful students \n"
			<< "4 - Sort students according to their marks \n"
			<< "5 - Get an average mark of particular student" << std::endl <<std::endl;

		int UserInput = 1;

		std::cin >> UserInput;

		switch (UserInput)
		{
			case 1:
			{

				Student* bestStudent = getBestStudent(students, SizeofList);
				if (bestStudent)
				{
					std::cout << "Best student: " << bestStudent->Name << " with average mark: "
						<< getAverageMark(*bestStudent) << std::endl << std::endl;
				};
				break;
			};
			case 2:
			{

				double SelectedMark = 0;

				std::cout << "Enter the average mark to set a treshold:" << std::endl;
				std::cin >> SelectedMark;

				std::cout << "Number of students with average mark above " 
					<< SelectedMark << ": "
					<< countAboveAverage(students, SizeofList, SelectedMark) <<std::endl << std::endl;

				break;
			};

			case 3:
			{
				unsigned percent = 0;
				Student beststudents[SizeofList];
				int beststudentslistsize = 0;

				std::cout << "Enter percentage you want to get: " << std::endl;
				std::cin >> percent;

				getBestStudents(students, SizeofList, beststudents, beststudentslistsize, percent);

				std::cout << "Top " << percent << "% students: " << std::endl;
				for (int i = 0; i < beststudentslistsize; i++)
				{
					std::cout << beststudents[i].Name << " with average mark: " << getAverageMark(beststudents[i]) << std::endl << std::endl;
				}
				break;
			}
			case 4:

				sortStudentsByAverage(students, SizeofList);
				
				std::cout << "Students sorted by average mark:" << std::endl;
				
				PrintStudentsList(students, SizeofList);

				std::cout << std::endl << std::endl;

				break;

			case 5:
			{
				std::string studentname;

				std::cout << "Enter the name of a student: " << std::endl;
				std::cin >> studentname;

				Student* foundStudent = FindaStudent(studentname, students, SizeofList);
				if (foundStudent == nullptr)
				{
					std::cout << "The student was not found." << std::endl << std::endl;
				}
				else
				{
					std::cout << "Average mark of " << studentname << " is " << getAverageMark(*foundStudent) << std::endl << std::endl;
				};

				break;
			}
			default:
				if (UserInput > 5)
				{
					std::cout << "No such command found. Please try again." << std::endl << std::endl;
				}
				break;
		};

		if (UserInput == 0)
		{
			std::cout << "You quit the programm." << std::endl << std::endl;
			break;
		}
	};

	return 0;
}


