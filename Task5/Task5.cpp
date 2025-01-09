// Task5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>

// Task5


#include <iostream>


int main()
{
	//1

	int a;
	int b;
	int c;

	std::cout << "Enter first element of progression:" << std::endl;
	std::cin >> a;

	std::cout << "Enter progression step:" << std::endl;
	std::cin >> b;

	std::cout << "Enter last element of progression:" << std::endl;
	std::cin >> c;
		
	std::cout << "Your Progression is: " << std::endl;
		
		for (int i = a; i <= c; i += b)
		{
			std::cout << i << std::endl;
		};
	
	std::cout << std::endl << std::endl;


	//2

	int ChosenShape;
	int NumberOfRows;
	int NumberOfColumns;

	std::cout << "Please chose your Shape. 1 - Rectangle, 2 - Reversed triangle, 3 - Triangle, 4 - Shifted rectangle, 6 - Triangle with numbers." << std::endl;
	std::cin >> ChosenShape;

	std::cout << "Please enter number of rows: " << std::endl;
	std::cin >> NumberOfRows;

	std::cout << "Please enter number of columns: " << std::endl;
	std::cin >> NumberOfColumns;

	if (ChosenShape == 1)
	{
		for (int i = 0; i < NumberOfRows; i++)
		{
			for (int j = 0; j < NumberOfColumns; j++)
			{
				std::cout << "* ";
			};

			std::cout << std::endl;
		};
	}
	else if (ChosenShape == 2)
	{
		for (int i = 0; i < NumberOfRows; i++)
		{
			for (int j = 0; j < NumberOfRows - i; j++)
			{
				std::cout << "* ";
			};

			std::cout << std::endl;
		};
	}
	else if (ChosenShape == 3)
	{
		for (int i = 0; i < NumberOfRows; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				std::cout << "* ";
			};

			std::cout << std::endl;
		};
	}
	else if (ChosenShape == 4)
	{
		for (int i = 0; i < NumberOfRows; i++)
		{
			for (int j = 0; j < i; j++)
			{
				std::cout << "  ";
			}
			for (int j = 0; j < NumberOfColumns; j++)
			{
				std::cout << "* ";
			};

			std::cout << std::endl;
		};
	}
	else if (ChosenShape == 5)
	{
		for (int i = 0; i < NumberOfRows; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if ((i + j) % 2 == 0)
					std::cout << "1 ";
				else
					std::cout << "0 ";
			};

			std::cout << std::endl;
		};
	};

	std::cout << std::endl << std::endl;



	//3

	char Character;
	int Sum = 0;

	while (true)
	{	
		std::cout << "Please enter a character. Enter '.' to exit" << std::endl;
		std::cin >> Character;
		std::cout << std::endl;


		if (Character == '.')
		{
			std::cout << "Program is finished." << std::endl << std::endl;
			break;
		}
		else if (islower(Character))
		{
			Character = toupper(Character);
			std::cout << "Upper Character: " << Character << std::endl << std::endl;
		}
		else if (isupper(Character))
		{
			std::cout << Character << std::endl << std::endl;
		}
		else if (isdigit(Character))
		{
			Sum += Character - '0';
			std::cout << "Your sum is: " << Sum << std::endl << std::endl;
		}
		else
		{
			std::cout << "Character is ivalid. Please enter a letter or a digit." << std::endl << std::endl;
		};
	}

	std::cout << std::endl << std::endl;


	//4

	int n;
	
	std::cout << "Enter the position of the Fibonacci sequence (n): " << std::endl;
	std::cin >> n;
	std::cout << std::endl;

	if (n <= 0)
	{
		std::cout << "Invalid input! Please enter a positive integer." << std::endl << std::endl;
	}
	else if (n == 1 || n == 2)
	{
		std::cout << "Fibonacci number at position " << n << " is: 1" << std::endl << std::endl;
	}
	else if (n > 2)
	{
		int PreviousOne = 1;
		int	PreviousTwo = 1;
		int Current;

		for (int i = 3; i <= n; ++i)
		{
			Current = PreviousOne + PreviousTwo;
			PreviousOne = PreviousTwo;
			PreviousTwo = Current;
		};
		std::cout << "Fibonacci number at position " << n << " is: " << Current << std::endl << std::endl;
	}
	else
	{
		std::cout << "Invalid input! Unable to detect Fibonacci number." << std::endl << std::endl;
	};

	//5

	int m;

	std::cout << "Please enter a positive integer number: " << std::endl;
	std::cin >> m;

	if (m < 0)
	{
		std::cout << "Invalid input. Please enter a positive integer." << std::endl;
	}
	else
	{
		int Multiplication = 2;

		for (int i = 2; i <= n; i++)
		{
			Multiplication *= i;
		}

		std::cout << "Factorial of " << m << "is equal to " << Multiplication << std::endl << std::endl;
	};

	return 0;
}