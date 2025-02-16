#pragma once

#include <string>

struct Student { std::string Name; double Marks[5]; };

Student* FindaStudent(const std::string& nameofastudent, Student students[], int size);

void PrintStudentsList(Student students[], int size);

double getAverageMark(const Student& student);

Student* getBestStudent(Student* students, unsigned size);

int countAboveAverage(Student* students, int size, double Treshold);

void getBestStudents(Student* inStudents, int inSize, Student* outStudents, int& outSize, unsigned percent);

void sortStudentsByAverage(Student* students, unsigned size);
