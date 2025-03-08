#include <iostream>
#include <string>
#include "DynamicIntArray.h"

int main()
{
    using T = int;

    std::size_t size;
    std::cout << "Enter initial size of array: ";
    std::cin >> size;

    DynamicIntArray<T> arr(size);
    std::cout << "Enter " << size << " elements: ";
    for (std::size_t i = 0; i < arr.getSize(); ++i)
    {
        std::cin >> arr[i];
    }

   int choice;
    do
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Print array\n";
        std::cout << "2. Push back element\n";
        std::cout << "3. Resize array\n";
        std::cout << "4. Reserve capacity\n";
        std::cout << "5. Shrink to fit\n";
        std::cout << "6. Pop back element\n";
        std::cout << "7. Clear array\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Array contents: ";
            for (std::size_t i = 0; i < arr.getSize(); ++i)
            {
                std::cout << arr[i] << " ";
            }
            std::cout << "\n";
            break;
        case 2:
        {
            T newElement;
            std::cout << "Enter an element to push back: ";
            std::cin >> newElement;
            arr.push_back(newElement);
            break;
        }
        case 3:
        {
            std::size_t newSize;
            std::cout << "Enter new size for resizing: ";
            std::cin >> newSize;
            arr.setSize(newSize);
            break;
        }
        case 4:
        {
            std::size_t reserveSize;
            std::cout << "Enter capacity to reserve: ";
            std::cin >> reserveSize;
            arr.reserve(reserveSize);
            std::cout << "New capacity: " << arr.getCapacity() << "\n";
            break;
        }
        case 5:
            arr.shrinkToFit();
            std::cout << "Array shrunk to fit size. New capacity: " << arr.getCapacity() << "\n";
            break;
        case 6:
            if (arr.getSize() > 0) {
                std::cout << "Removing last element: " << arr.back() << "\n";
                arr.pop_back();
            }
            else {
                std::cout << "Array is empty!\n";
            }
            break;
        case 7:
            arr.clear();
            std::cout << "Array cleared.\n";
            break;
        case 0:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
