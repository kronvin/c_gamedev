// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

//4
// Create Enum Class
enum class WeekDay
{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};


int main()
{
    // 1
    // Assign vars
    int a, b;

    // Input vars
    cout << "Enter first integer:" << endl;
    cin >> a;

    cout << "Enter second integer:" << endl;
    cin >> b;

    //Replace
    
    int c = a;

    a = b;
    b = c;
    
    // Output
    cout << "First number is " << a << endl;
    cout << "Second number is " << b << endl << endl;


    // 2
    // Double initialisation
    double d = 12.344454523868864746472;

    // Output
    cout << "Double: " << d << endl;

    int MyInt = static_cast<int>(d);

    // Cast to int
    cout << "As int: " << MyInt << endl;

    // Alignment
    cout << "Aligned: " << setw(20) << setfill('$') << MyInt << endl << endl;


    //3
    // Set Presicion
    cout << fixed << setprecision(2) << "Precision 2: " << d << endl;
    cout << fixed << setprecision(5) << "Precision 5: " << d << endl;
    cout << fixed << setprecision(10) << "Precision 10: " << d << endl;

    // Notation
    cout << scientific << "E-notation: " << d << endl;
    cout << defaultfloat << "Standard notation: " << d << endl << endl;
    
    
    // 4 (continue
    for (int i = static_cast<int>(WeekDay::Monday); i <= static_cast<int>(WeekDay::Sunday); ++i)
    {
        cout << "Day " << i << ": " << static_cast<int>(static_cast<WeekDay>(i)) << endl;
    };

    cout << "Done!" << endl << endl;

    // 5
    // Input Number
    int InputBool;

    cout << "Enter a number: " << endl;
    cin >> InputBool;

    bool BoolChanged = static_cast<bool>(InputBool);

    // True/False output
    cout << boolalpha << "Boolean value: " << BoolChanged << endl << endl;
    
}

