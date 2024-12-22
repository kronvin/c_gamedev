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
	else if (FirstNum == SecondNum || FirstNum == ThirdNum || SecondNum == ThirdNum)
	{
		int max = (FirstNum > SecondNum) ? FirstNum : SecondNum;
		max = (SecondNum > ThirdNum) ? SecondNum : ThirdNum;
		max = (ThirdNum > FirstNum) ? ThirdNum : FirstNum;

		std::cout << "The greatest number is " << max << std::endl << std::endl;              //Corrected
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

	int MonthNumber;

	std::cout << "Please enter month number: " << std::endl;
	std::cin >> MonthNumber;

	Month monthnum = static_cast<Month>(MonthNumber);

	if (MonthNumber < 0 || MonthNumber > 12)
	{
		std::cout << "There is no such month." << std::endl << std::endl;
	};

	switch (monthnum)
	{
	case Month::Jan:
	case Month::Feb:
	case Month::Dec:

		std::cout << "Season - Winter" << std::endl << std::endl;
		break;

	case Month::Mar:
	case Month::Apr:
	case Month::May:

		std::cout << "Season - Spring" << std::endl << std::endl;
		break;

	case Month::Jun:
	case Month::Jul:
	case Month::Aug:

		std::cout << "Season - Summer" << std::endl << std::endl;
		break;

	case Month::Sep:
	case Month::Oct:
	case Month::Nov:

		std::cout << "Season - Autumn" << std::endl << std::endl;
		break;                                                           // Corrected

	};


	//5

	double min;
	double NumberA;
	double NumberB;

	std::cout << "Please enter two numbers." << std::endl;
	std::cin >> NumberA;
	std::cin >> NumberB;

	if (NumberA == NumberB)                                                    // "=" instead of "==" :/ sorry
	{
		std::cout << "There's no lowest number." << std::endl << std::endl;
	}
	else
	{
		min = (NumberA < NumberB) ? NumberA : NumberB;
		std::cout << "The lowest number is " << min << std::endl << std::endl;
	};


	//6

	int MonthNum;

	std::cout << "Select month. Please enter a number between 1 and 12: " << std::endl;
	std::cin >> MonthNum;

	if (MonthNum < 1 || MonthNum > 12)
	{
		std::cout << "Wrong number. There is no such month" << std::endl << std::endl;
	}
	else
	{
		Month month = static_cast<Month>(MonthNum);

		switch (month)
		{
		case Month::Jan:
			std::cout << "The month is January" << std::endl << std::endl;
			break;
		case Month::Feb:
			std::cout << "The month is February" << std::endl << std::endl;
			break;
		case Month::Mar:
			std::cout << "The month is March" << std::endl << std::endl;
			break;
		case Month::Apr:
			std::cout << "The month is April" << std::endl << std::endl;
			break;
		case Month::May:
			std::cout << "The month is May" << std::endl << std::endl;
			break;
		case Month::Jun:
			std::cout << "The month is June" << std::endl << std::endl;
			break;
		case Month::Jul:
			std::cout << "The month is July" << std::endl << std::endl;
			break;
		case Month::Aug:
			std::cout << "The month is August" << std::endl << std::endl;
			break;
		case Month::Sep:
			std::cout << "The month is September" << std::endl << std::endl;
			break;
		case Month::Oct:
			std::cout << "The month is October" << std::endl << std::endl;
			break;
		case Month::Nov:
			std::cout << "The month is November" << std::endl << std::endl;
			break;
		case Month::Dec:
			std::cout << "The month is December" << std::endl << std::endl;
			break;
		};
	};                                                                               // Corrected
	return 0;
};
