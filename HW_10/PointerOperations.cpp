

//1

void SwapFirstMethod(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SwapSecondMethod(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
};


//2

bool FindinArray(const int* arr, int size, int elem)
{
	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) == elem)
		{
			return true;
		};
	};
	
	return false;
}


////3
bool CalculateSum(const double* arr, int arrSize, double& sum)
{
	if (arrSize <= 0)
	{
		return false;
	}

	for (int i = 0; i < arrSize; i++)
	{
		sum += *(arr + i);
	}

	return true;
}