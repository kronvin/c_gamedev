#include <iostream>
#include <vector>
#include "Vector.h"

int main()
{
    std::vector<Vector2d> vectors;

    while (true)
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add two vectors\n";
        std::cout << "2. Show all vectors\n";
        std::cout << "3. Show instance count\n";
        std::cout << "4. Multiply vectors by scalar\n";
        std::cout << "5. Clear all vectors and restart\n";
        std::cout << "6. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Vector2d v1, v2;
            std::cout << "Enter first vector (x y): ";
            std::cin >> v1;
            std::cout << "Enter second vector (x y): ";
            std::cin >> v2;

            Vector2d sum = v1 + v2;
            Vector2d diff = v1 - v2;

            std::cout << "Sum: " << sum << std::endl;
            std::cout << "Difference: " << diff << std::endl;

            vectors.push_back(v1);
            vectors.push_back(v2);
            vectors.push_back(sum);
            vectors.push_back(diff);
            break;
        }

        case 2:
        {
            if (vectors.empty())
            {
                std::cout << "No vectors stored yet.\n";
            }
            else
            {
                std::cout << "Stored vectors:\n";
                for (size_t i = 0; i < vectors.size(); i++)
                {
                    std::cout << "Vector " << i + 1 << ": " << vectors[i] << std::endl;
                }
            }
            break;
        }

        case 3:
            std::cout << "Active instances: " << Vector2d::getInstanceCount() << std::endl;
            break;

        case 4:
        {
            if (vectors.empty())
            {
                std::cout << "No vectors to scale.\n";
            }
            else
            {
                float scalar;
                std::cout << "Enter scalar value: ";
                std::cin >> scalar;
                std::cout << "Vectors after scaling:\n";

                for (auto& vec : vectors)
                {
                    vec *= scalar;
                    std::cout << vec << std::endl;
                }
            }
            break;
        }

        case 5:
            vectors.clear();
            std::cout << "All vectors removed. You can start again.\n";
            break;

        case 6:
            std::cout << "Exiting program.\n";
            return 0;

        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    }

    return 0;
}
