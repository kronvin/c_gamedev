// HW_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LoopFunctions.h"
#include "Recursion.h"
#define _USE_MATH_DEFINES
#include <math.h>

//3
//Функції обрахунку площі та довжини кола: float getArea(float radius), float getCircumference(float radius);
float GetArea(float radius)
{
    float Area = 0;

    if (radius <= 0)
    {
        std::cout << "This circle do not exist." << std::endl << std::endl;
        return 0;
    }
    else
    {
        Area = radius * radius * M_PI;
        return Area;
    };
};

float GetCircleLength(float radius)
{
    float Length = 0;

    if (radius <= 0)
    {
        std::cout << "This circle do not exist." << std::endl << std::endl;
        return 0;
    }
    else
    {
        Length = radius * M_PI * 2;
        return Length;
    };
};


int main()
{
    //1
    int n = 0;

    std::cout << "Please enter how many numbers you want to check: " << std::endl;
    std::cin >> n;

    CheckOutNumbers(n);


    //2
    int Count = 0;

    std::cout << "Please enter a number to count a factorial: " << std::endl;
    std::cin >> Count;

    Factorial(Count);

    //2(1)
    std::cout << "The result of recursion function is: " << FactorialRecursion(Count) << std::endl << std::endl;;


    //3
    float Radius;

    std::cout << "Please enter circle's radius: " << std::endl;
    std::cin >> Radius;

    std::cout << "Circle Area is " << GetArea(Radius) << std::endl;
    std::cout << "Circle Length is " << GetCircleLength(Radius) << std::endl << std::endl;


    //4
    int Number = 0;

    std::cout << "Please enter a natural number: " << std::endl;
    std::cin >> Number;

    std::cout << "Your numbers from high to low: " << std::endl;
    PrintNumbers_High_Low(Number);

    std::cout << "Your numbers from high to low: " << std::endl;
    PrintNumbers_Low_High(Number);

    std::cout << std::endl;


    //4(1)
    int number = 0;

    std::cout << "Please enter a natural number to use a recursion function: " << std::endl;
    std::cin >> number;

    std::cout << "Your numbers from high to low: " << std::endl;
    RecNumbers_High_Low(number);

    std::cout << "Your numbers from high to low: " << std::endl;
    RecNumbers_Low_High(number);

    std::cout << std::endl;



    return 0;

}

