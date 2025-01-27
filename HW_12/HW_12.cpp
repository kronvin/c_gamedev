// HW_12.cpp

#include <iostream>

constexpr unsigned int ROWS = 5;
constexpr unsigned int COLUMNS = 6;


//1 - Bubble sort
void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
};


//2 - Sort by rows and columns
enum class SortingDirection
{
    ByRows,
    ByColumns
};

void SortArray(int arr[ROWS][COLUMNS], SortingDirection direction)
{
    if (direction == SortingDirection::ByRows)
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS - 1; j++)
            {
                for (int k = 0; k < COLUMNS - j - 1; k++)
                {
                    if (arr[i][k] > arr[i][k + 1])
                    {
                        int temp = arr[i][k + 1];
                        arr[i][k + 1] = arr[i][k];
                        arr[i][k] = temp;
                    }
                }
            }
        }
    }
    if (direction == SortingDirection::ByColumns)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            for (int i = 0; i < ROWS - 1; i++)
            {
                for (int k = 0; k < ROWS - i - 1; k++)
                {
                    if (arr[k][j] > arr[k+1][j])
                    {
                        int temp = arr[k][j];
                        arr[k][j] = arr[k + 1][j];
                        arr[k + 1][j] = temp;
                    }
                }

            }
        }
    }
}


int main()
{
    //1
    int RandomArray[] = {4, 6, 2, 1, 10};
    int SIZE = sizeof(RandomArray) / sizeof(RandomArray[0]);

    std::cout << "Current array is: " << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << RandomArray[i] << " ";
    };

    std::cout << std::endl;

    BubbleSort(RandomArray, SIZE);

    std::cout << "Sorted array: " << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << RandomArray[i] << " ";
    };

    std::cout << std::endl << std::endl;

    //2
    int RandomArray2[ROWS][COLUMNS] =
    {
      {2, 1, 6, 4, 3, 5},
      {3, 5, 2, 1, 2, 4},
      {5, 4, 4, 3, 1, 2},
      {1, 2, 6, 4, 5, 3},
      {4, 3, 1, 2, 6, 5},
    };

    std::cout << "Current array is: " << std::endl;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            std::cout << RandomArray2[i][j] << " " << " ";
        }

        std::cout << std::endl;
    };

    std::cout << std::endl;

    int Choice = 0;

	std::cout << "Please choose the direction for sorting (0 - by rows, 1 - by column): " << std::endl;
    std::cin >> Choice;

    SortingDirection direction = static_cast<SortingDirection>(Choice);
   
    SortArray(RandomArray2, direction);

    std::cout << std::endl;

    std::cout << "Sorted array is: " << std::endl;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            std::cout << RandomArray2[i][j] << " " << " ";
        }

        std::cout << std::endl;
    };

    return 0;
}