// HW_9.cpp

#include <iostream>
#include "Functions.h";

int main()
{
    //1

    const int size = 10;
    int numbers[size];

    std::cout << "Enter numbers to fill the array: " << std::endl;

    for (int i = 0; i <= (size - 1); i++)
    {
        std::cin >> numbers[i];
    };

    std::cout << std::endl;

    TranslateArray(numbers, size);

    std::cout << "Translated array: " << std::endl;
    
    for (int i = 0; i <= (size - 1); i++)
    {
        std::cout << numbers[i] << " ";
    };

    std::cout << std::endl << std::endl;

    //2
    char String[100];
    
    std::cout << "Enter a string." << std::endl;
    std::cin >> String;

    ToUppercase(String);

    std::cout << "Your transformed string: " << std::endl;
    std::cout << String << std::endl << std::endl;


    //3
    char PalindromeCandidate[100];

    std::cout << "Please enter your string." << std::endl;
    std::cin >> PalindromeCandidate;

    if (IsPalindrome(PalindromeCandidate))
    {
        std::cout << "The string is a palindrome." << std::endl << std::endl;
    }
    else
    {
        std::cout << "The string isn't a palindrome." << std::endl << std::endl;
    }


    //4
    char CountString[100];
    std::cout << "Please enter new string." << std::endl;
    std::cin >> CountString;
   
    int VowelsCount = 0;
    int ConsonCount = 0;

    CountVowCons(CountString, VowelsCount, ConsonCount);

    std::cout << "The number of vowels: " << VowelsCount << std::endl;
    std::cout << "The number of consonants: " << ConsonCount << std::endl << std::endl;


    //5
    char FirstString[100];
    char SecondString[100];

    std::cout << "Enter first string: " << std::endl;
    std::cin >> FirstString;
    std::cout << "Enter second string: " << std::endl;
    std::cin >> SecondString;

    if (IsEqual(FirstString, SecondString))
    {
        std::cout << "Two strings are equal." << std::endl << std::endl;
    }
    else
    {
        std::cout << "Two strings are not equal." << std::endl << std::endl;
    };


    return 0;
}

