// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int main()
{
    //1
    int GameTime;

    cout << "Enter your seconds in game:" << endl;
    cin >> GameTime;

    int hours = GameTime / 3600;                 // Divide to get hours
    int remainingSeconds = GameTime % 3600;      // Get the remaining seconds after receiving the hours
    int minutes = remainingSeconds / 60;         // Get minutes from remaining seconds
    int seconds = remainingSeconds % 60;         // Remaining seconds after dividing 

    cout << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << endl << endl;


    //2
    int FirstNumber, SecondNumber, ThirdNumber;

    cout << "Enter first number:" << endl;
    cin >> FirstNumber;

    cout << "Enter second number:" << endl;
    cin >> SecondNumber;

    cout << "Enter third number:" << endl;
    cin >> ThirdNumber;

    
    int Multiplication = FirstNumber * SecondNumber * ThirdNumber;
    int Sum = FirstNumber + SecondNumber + ThirdNumber;

    cout << "Multiplication: " << Multiplication << endl;
    cout << "Sum: " << Sum << endl;
    cout << "Average: " << Sum / 3 << endl << endl;


    //3
    int CompareFirst;
    int CompareSecond;

    cout << "Enter first number to compare:" << endl;
    cin >> CompareFirst;

    cout << "Enter second number to compare:" << endl;
    cin >> CompareSecond;

    bool lessThan = CompareFirst < CompareSecond;
    bool equal = CompareFirst == CompareSecond;
    bool moreThan = CompareFirst > CompareSecond;
    bool lessOrEqual = CompareFirst <= CompareSecond;

    cout << boolalpha << CompareFirst << " lessThan " << CompareSecond << ": " << lessThan << endl;
    cout << boolalpha << CompareFirst << " equal " << CompareSecond << ": " << equal << endl;
    cout << boolalpha << CompareFirst << " moreThan " << CompareSecond << ": " << moreThan << endl;
    cout << boolalpha << CompareFirst << " lessOrEqual " << CompareSecond << ": " << lessOrEqual << endl << endl;


    //4
    int height;
    int width;

    cout << "Enter rectangle height:" << endl;
    cin >> height;

    cout << "Enter rectangle width:" << endl;
    cin >> width;

    int perimeter = 2 * (width + height);
    int area = height * width;

    cout << "Rectangle perimeter is " << perimeter << " cm." << endl;
    cout << "Rectangle area is " << area << " cm." << endl << endl;


    //5

    double radius;
    const double PI = 3.14;

    cout << "Enter circle radius: " << endl;
    cin >> radius;

    double CircleArea = radius * radius * PI;
    double CircleLength = 2 * PI * radius;

    cout << "Circle area is " << CircleArea << " cm." << endl;
    cout << "Circle length is " << CircleLength << " cm." << endl << endl;


    return 0;
}

