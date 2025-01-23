// HW_10.cpp

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "PointerOperations.h"


using std::cout;
using std::cin;
using std::endl;


//3) Створити функцію яка записує у змінну sum суму всіх елементів довільного масиву, повертає true, якщо розмір масиву > 0.



int main()
{
	//1
	
	int a = 0;
	int b = 0;

	cout << "Please enter first integer." << endl;
	cin >> a;

	cout << "Please enter second integer." << endl;
	cin >> b;

	cout << "We swap a = " << a << " with b = " << b << "." << endl;

	SwapFirstMethod(a, b);

	cout << "Now a = " << a << " and b = " << b << "." << endl;
	
	cout << "Let's swap again!" << endl;
	
	SwapSecondMethod(&a, &b);

	cout << "Now a = " << a << " and b = " << b << "." << endl << endl;


	//2

	const int size = 50;
	int arr[size];
	int Element = 0;

	cout << "Generating an array..." << endl;

	srand(static_cast<unsigned>(time(0)));

	for (int i = 0; i < size; i++)
	{
		arr[i] = -50 + rand() % (50 - (-50) + 1);
	}

	std::this_thread::sleep_for(std::chrono::seconds(3));

	cout << "Array has been generated!" << endl;
	cout << "Fifth element in the array: " << arr[5] << endl;           ///For checking true case
	cout << "Please enter an integer you are looking for: " << endl;
	cin >> Element;

	cout << "Looking for an element..." << endl;

	std::this_thread::sleep_for(std::chrono::seconds(3));

	if (FindinArray(arr, size, Element))
	{
		cout << "The element is present in the array." << endl << endl;
	}
	else
	{
		cout << "The element is not present in the array." << endl << endl;
	};


	//3
	cout << "Another array is {0, 5, 10, -4, 2.5}." << endl;
	cout << "Calculating the sum of the array..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));


	const int SizeofArray = 5;
	const double Array[SizeofArray] = {0, 5, 10, -4, 2.5};
	double ArraySum = 0;

	if (CalculateSum(Array, SizeofArray, ArraySum))
	{
		cout << "Size of Array > 0." << endl;
		cout << "Sum of Array elements = " << ArraySum << "." << endl << endl;
	}
	else
	{
		cout << "Size of Array < 0." << endl << endl;
	};


	return 0;
}

