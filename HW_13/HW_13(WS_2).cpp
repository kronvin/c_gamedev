// HW_12(WS_2).cpp


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>


int main() 
{

    std::fstream file("Words.txt", std::ios_base::in);

    if (!file.is_open()) 
    {
        std::cerr << "Filed to open the file." << std::endl;
        return 1;
    }

    int size = 0;
    file >> size;

    if (size == 0) 
    {
        std::cerr << "File does not contain any words." << std::endl;
        return 1;
    }

    std::vector<std::string> database(size);

    for (int i = 0; i < size; i++) 
    {
        file >> database[i];
    }

    file.close();  

    while (true)
    {
        srand(time(0));
        std::string randomWord = database[rand() % size];

        /*std::cout << randomWord << std::endl;*/

        std::cout << "Try to guess the word! Please enter the word (Enter 'EXIT' to quit):" << std::endl << std::endl;

        int attempts = 0;
        std::string userWord;

        while (true)
        {
            std::cin >> userWord;
            std::transform(userWord.begin(), userWord.end(), userWord.begin(), ::toupper);

            if (userWord == "EXIT")
            {
                std::cout << "Thanks for playing! Bye!" << std::endl << std::endl;
                return 0;
            };

            attempts++;

            if (userWord.length() != 5)
            {
                std::cout << "Please enter the word of five letters." << std::endl;
                continue;
            }

            std::string result = "*****";
            std::string tempWord = randomWord;

            for (int i = 0; i < 5; i++)
            {
                if (userWord[i] == tempWord[i])
                {
                    result[i] = toupper(userWord[i]);
                    tempWord[i] = ' ';
                }
            }

            for (int i = 0; i < 5; i++)
            {
                if (result[i] == '*')
                {
                    size_t pos = tempWord.find(userWord[i]);

                    if (pos != std::string::npos)
                    {
                        result[i] = tolower(userWord[i]);
                        tempWord[pos] = ' ';
                    }
                }
            }

            std::cout << result << std::endl << std::endl;

            if (userWord == randomWord)
            {
                std::cout << "You guessed the word in " << attempts << " attempts." << std::endl << std::endl;
                break;
            }
        }
    }

    return 0;
}