
#include <iostream>
#include "LoopFunctions.h"


//1
void CheckOutNumbers(int n)
{
	int UserNumber = 0;

	int Positive = 0;
	int Negative = 0;
	int Zeroes = 0;

	for (int i = 1; i <= n; i++)
	{
		std::cout << "Please enter an integer: " << std::endl;
		std::cin >> UserNumber;

		if (UserNumber == 0)
		{
			Zeroes += 1;
		}
		else if (UserNumber < 0)
		{
			Negative += 1;
		}
		else
		{
			Positive += 1;
		};
	};

	std::cout << "Positive: " << Positive << std::endl;
	std::cout << "Negative: " << Negative << std::endl;
	std::cout << "Zeroes: " << Zeroes << std::endl << std::endl;

	return;
}


//2
int Factorial(int Count)
{
	int Factorial = 1;

	for (int i = 1; i <= Count; i++)
	{
		Factorial *= i;
	}

	std::cout << "The factorial for " << Count << " is " << Factorial << "." << std::endl << std::endl;

	return Factorial;
}


//4
//від найбільшого до найменшого за допомогою рекурсії;
//від найменшого до найбільшого за допомогою рекурсії;
void PrintNumbers_High_Low(int Number)
{
	for (int i = Number; i >= 1; i --)
	{
		std::cout << i << std::endl;
	}

	return;
}

void PrintNumbers_Low_High(int Number)
{
	for (int i = 1; i <= Number; i++)
	{
		std::cout << i << std::endl;
	}

	return;
}