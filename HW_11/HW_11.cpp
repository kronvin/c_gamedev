// HW_11.cpp

#include <iostream>

constexpr unsigned int ROWS = 4;
constexpr unsigned int COLUMNS = 6;

//1
bool Find(int arr_2d[ROWS][COLUMNS], int toFind)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (toFind == arr_2d[i][j])
            {
                return true;
            }
        }
    }

    return false;
};

//2
enum class SortingDirection
{
    Ascending,
    Descending
};

bool IsSorted(const int* arr, int size, SortingDirection direction)
{
    if (direction == SortingDirection::Ascending)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return false;
            }
            return true;
        }
    }
    if (direction == SortingDirection::Descending)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                return false;
            }
            return true;
        }
    }
    return false;
};

//3(1)
void TraverseTopDownRightLeftByColumns(int arr_2d[ROWS][COLUMNS])
{
    for (int j = COLUMNS - 1; j >= 0; j--)
    {
        for (int i = 0; i < ROWS; i++)
        {
            std::cout << arr_2d[i][j] << " " << " ";
        }

        std::cout << std::endl;
    }
}

//3(2)
void TraverseLeftRightDownTopSwitchingByRows(int arr_2d[ROWS][COLUMNS])
{
    for (int i = ROWS - 1; i >= 0; i--)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            std::cout << arr_2d[i][j] << " " << " ";
        }

        std::cout << std::endl;
    }
};


int main()
{
    int arr_2d[ROWS][COLUMNS] = {
      {11, 12, 13, 14, 15, 16 },
      {21, 22, 23, 24, 25, 26 },
      {31, 32, 33, 34, 35, 36 },
      {41, 42, 43, 44, 45, 46 }
    };

    //1
    int NumbertoFind = 0;

    std::cout << "Please enter a number to find in the array." << std::endl;
    std::cin >> NumbertoFind;

    std::cout << "The result of search is: " << (Find(arr_2d, NumbertoFind) ? "true" : "false") << std::endl << std::endl;


    //2
    int arr1[5] = { 1, 2, 3, 4, 5 }; // For testing
    int arr2[5] = { 5, 4, 3, 2, 1 }; 
    int arr3[5] = { 1, 2, 5, 4, 3 }; 

    std::cout << "The array is sorted in ascending order: " << (IsSorted(arr1, 5, SortingDirection::Ascending) ? "true" : "false") << std::endl;
    std::cout << "The array is sorted in desscending order: " << (IsSorted(arr1, 5, SortingDirection::Descending) ? "true" : "false") << std::endl << std::endl;


    //3(1)
    std::cout << "Your array from top to down and from right to left: " << std::endl;
    TraverseTopDownRightLeftByColumns(arr_2d);
    std::cout << std::endl << std::endl;
   
    //3(2)
    std::cout << "Your array from left to right and from down to top: " << std::endl;
    TraverseLeftRightDownTopSwitchingByRows(arr_2d);
    std::cout << std::endl << std::endl;

    return 0;
}