// Task 4 

#include <iostream>



int main()
{
	// 1

	double FirstNum;
	double SecondNum;
	double ThirdNum;

	std::cout << "Please enter three numbers: " << std::endl;
	std::cin >> FirstNum;
	std::cin >> SecondNum;
	std::cin >> ThirdNum;

	if (FirstNum > SecondNum && FirstNum > ThirdNum)
	{
		std::cout << "The greatest numer is " << FirstNum << std::endl << std::endl;
	}
	else if (SecondNum > FirstNum && SecondNum > ThirdNum)
	{
		std::cout << "The greatest numer is " << SecondNum << std::endl << std::endl;
	}
	else if (ThirdNum > FirstNum && ThirdNum > SecondNum)
	{
		std::cout << "The greatest numer is " << ThirdNum << std::endl << std::endl;
	}
	else if (FirstNum == SecondNum && FirstNum == ThirdNum && SecondNum == ThirdNum)
	{
		std::cout << "There is no greater number." << std::endl << std::endl;
	}
	else
	{
		std::cout << "There is no greater number." << std::endl << std::endl;
	};


	//2

	int UserNumber;

	std::cout << "Please enter any number." << std::endl;
	std::cin >> UserNumber;

	int a = UserNumber % 5;
	int b = UserNumber % 11;

	if (a == 0 && b == 0)
	{
		std::cout << "The number is divisible by 5 and 11" << std::endl << std::endl;
	}
	else
	{
		std::cout << "The number is not divisible by 5 and 11" << std::endl << std::endl;
	};


	//3

	double AngleOne;
	double AngleTwo;
	double AngleThree;

	std::cout << "Enter three values for the angles of the triangle: " << std::endl;
	std::cin >> AngleOne;
	std::cin >> AngleTwo;
	std::cin >> AngleThree;

	double Sum = AngleOne + AngleTwo + AngleThree;

	if (Sum == 180 && AngleOne > 0 && AngleTwo > 0 && AngleThree > 0)
	{
		std::cout << "It's a triangle." << std::endl << std::endl;
	}
	else
	{
		std::cout << "It's not a triangle." << std::endl << std::endl;
	};


	//4

	int MonthNumber;

	std::cout << "Please enter month number: " << std::endl;
	std::cin >> MonthNumber;

	if (MonthNumber < 0 || MonthNumber > 12)
	{
		std::cout << "There is no such month." << std::endl << std::endl;
	}
	else if (MonthNumber >= 3 && MonthNumber <= 5)
	{
		std::cout << "Season - Spring" << std::endl << std::endl;
	}
	else if (MonthNumber >= 6 && MonthNumber <= 8)
	{
		std::cout << "Season - Summer" << std::endl << std::endl;
	}
	else if (MonthNumber >= 9 && MonthNumber <= 11)
	{
		std::cout << "Season - Autumn" << std::endl << std::endl;
	}
	else
	{
		std::cout << "Season - Winter" << std::endl << std::endl;
	};


	//5

	double min;
	double NumberA;
	double NumberB;

	std::cout << "Please enter two numbers." << std::endl;
	std::cin >> NumberA;
	std::cin >> NumberB;

	if (NumberA = NumberB)
	{
		std::cout << "There's no lowest number." << std::endl << std::endl;
	}
	else
	{
		min = (NumberA < NumberB) ? NumberA : NumberB;
		std::cout << "The lowest number is " << min << std::endl << std::endl;
	};


	//6

	enum class Month
	{
		Jan = 1,
		Feb,
		Mar,
		Apr,
		May,
		Jun,
		Jul,
		Aug,
		Sep,
		Oct,
		Nov,
		Dec
	};

	int MonthNum;

	std::cout << "Select month. Please enter a number between 1 and 12: " << std::endl;
	std::cin >> MonthNum;

	if (MonthNum < 1 || MonthNum > 12)
	{
		std::cout << "Wrong number. There is no such month" << std::endl << std::endl;
	};

	Month month = static_cast<Month>(MonthNum);

	switch (month)
	{
	case Month::Jan:
		std::cout << "The month is January";
		break;
	case Month::Feb:
		std::cout << "The month is February";
		break;
	case Month::Mar:
		std::cout << "The month is March";
		break;
	case Month::Apr:
		std::cout << "The month is April";
		break;
	case Month::May:
		std::cout << "The month is May";
		break;
	case Month::Jun:
		std::cout << "The month is June";
		break;
	case Month::Jul:
		std::cout << "The month is July";
		break;
	case Month::Aug:
		std::cout << "The month is August";
		break;
	case Month::Sep:
		std::cout << "The month is September";
		break;
	case Month::Oct:
		std::cout << "The month is October";
		break;
	case Month::Nov:
		std::cout << "The month is November";
		break;
	case Month::Dec:
		std::cout << "The month is December";
		break;
	};

	return 0;
};
