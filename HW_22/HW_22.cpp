// HW_22.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//1
void printStringVector(const std::vector<std::string>& vector)
{
    for (const auto& str : vector)
    {
        std::cout << str << std::endl;
    }

    std::cout << std::endl;
}

//a
bool compareByLength(const std::string& a, const std::string& b)
{
    return a.length() > b.length();
}

//b
class LengthComparator
{
public:
    bool operator()(const std::string& a, const std::string& b) const
    {
        return a.length() < b.length();
    }
};

//c
auto isInRangeLambda = [](const std::string& a, const std::string& b)
    {
        return a.length() > b.length();
    };

//Switched ascending-descending order to be sure that all functions work properly

//2

void fillNumbersVector(std::vector<int>& vector, int firstelement, int lastelement, int step) 
{
    for (int i = firstelement; i <= lastelement; i += step)
    {
        vector.push_back(i);
    };
};

void printNumbersVector(const std::vector<int>& vector)
{
    for (const auto& number : vector)
    {
        std::cout << number << ", ";
    };
}


unsigned int countDivisibleBy(const std::vector<int>& vector, int number)
{
    return std::count_if(vector.begin(), vector.end(), [number](int val)
        {
            return val % number == 0;
        });
}

int main()
{
    //1
    std::vector<std::string> stringContainer;
    std::vector<int> numbersContainer;

    stringContainer.push_back("ab");
    stringContainer.push_back("abcdefg");
    stringContainer.push_back("abc");
    stringContainer.push_back("a");
    stringContainer.push_back("abcde");
    stringContainer.push_back("abcdef");
    stringContainer.push_back("abcd");

    std::cout << "Original vector contains: " << std::endl;
    printStringVector(stringContainer);


    std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);
    std::cout << "Vector sorted with function: " << std::endl;
    printStringVector(stringContainer);

    std::sort(stringContainer.begin(), stringContainer.end(), LengthComparator());
    std::cout << "Vector sorted with functional class: " << std::endl;
    printStringVector(stringContainer);

    std::sort(stringContainer.begin(), stringContainer.end(), isInRangeLambda);
    std::cout << "Vector sorted with lambda: " << std::endl;
    printStringVector(stringContainer);


    //2
    fillNumbersVector(numbersContainer, 1, 20, 1);
    std::cout << "Numbers in the container:\n";
    printNumbersVector(numbersContainer);

    std::cout << std::endl;

    std::cout << "Numbers in the container divisible by 2:\n";
    std::cout << countDivisibleBy(numbersContainer, 2) << std::endl;

    std::cout << "Numbers in the container divisible by 5:\n";
    std::cout << countDivisibleBy(numbersContainer, 5) << std::endl;

    std::cout << "Numbers in the container divisible by 1:\n";
    std::cout << countDivisibleBy(numbersContainer, 1) << std::endl;

    std::cout << "Numbers in the container divisible by 20:\n";
    std::cout << countDivisibleBy(numbersContainer, 20) << std::endl;
}

