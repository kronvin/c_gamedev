// HW_7(WS_1).cpp


#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    char CompOptions[3] = { 's', 'r', 'p' };
    std::srand(std::time(0));

    while (true)
    {
        int Turns = 0;
        int PlayerWins = 0;
        int CompWins = 0;
        int Ties = 0;

        std::cout << "How many turns do you want to play? (-1 for quit)" << std::endl;
        std::cin >> Turns;

        if (Turns == -1)
        {
            std::cout << "Game is finished." << std::endl;
            break;
        }
        else if (Turns >= 1)
        {
            for (int i = 1; i <= Turns; i++)
            {
                char PlayerChoice;

                std::cout << "To make your turn choose one of possible symbols: " << std::endl;
                std::cout << "s - scissors   r - rock   p - paper" << std::endl;
                std::cin >> PlayerChoice;

                if (PlayerChoice != 's' && PlayerChoice != 'r' && PlayerChoice != 'p')
                {
                    std::cout << "Wrong character. Please choose an existing option." << std::endl << std::endl;
                    i -= 1;
                    continue;
                };

                int randomIndex = std::rand() % 3;
                char CompChoice = CompOptions[randomIndex];
                std::cout << "Computer choice is " << CompChoice << std::endl;

                if (PlayerChoice == CompChoice)
                {
                    std::cout << "It's a tie!" << std::endl << std::endl;
                    Ties += 1;
                }
                else if (PlayerChoice == 's' && CompChoice == 'p')
                {
                    std::cout << "Player wins!" << std::endl << std::endl;
                    PlayerWins += 1;
                }
                else if (PlayerChoice == 'r' && CompChoice == 's')
                {
                    std::cout << "Player wins!" << std::endl << std::endl;
                    PlayerWins += 1;
                }
                else if (PlayerChoice == 'p' && CompChoice == 'r')
                {
                    std::cout << "Player wins!" << std::endl << std::endl;
                    PlayerWins += 1;
                }
                else if (PlayerChoice == 'r' && CompChoice == 'p')
                {
                    std::cout << "Computer wins!" << std::endl << std::endl;
                    CompWins += 1;
                }
                else if (PlayerChoice == 's' && CompChoice == 'r')
                {
                    std::cout << "Computer wins!" << std::endl << std::endl;
                    CompWins += 1;
                }
                else if (PlayerChoice == 'p' && CompChoice == 's')
                {
                    std::cout << "Computer wins!" << std::endl << std::endl;
                    CompWins += 1;
                };
            };

            std::cout << "Thanks for playing!" << std::endl;
            std::cout << "Your final stats:" << std::endl;
            std::cout << "You played " << Turns << " turns." << std::endl;
            std::cout << "The number of ties is " << Ties << std::endl;
            std::cout << "You won " << PlayerWins << " times." << std::endl;
            std::cout << "You lost " << CompWins << " times." << std::endl << std::endl;

            if (CompWins >= PlayerWins)
            {
                std::cout << "Computer is the champion!" << std::endl << std::endl;
            }
            else
            {
                std::cout << "You are the champion!" << std::endl << std::endl;
            };
        }
        else
        {
            std::cout << "Please enter a positive integer to start the game." << std::endl << std::endl;
            break;
        };
    }

    return 0;
}

