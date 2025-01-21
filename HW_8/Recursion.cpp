
#include <iostream>
#include "Recursion.h"


//2(1)
int FactorialRecursion(int Count)
{
	if (Count <= 1)
	{
		return 1;
	}
	return Count * FactorialRecursion(Count - 1);
}

//4(1)
void RecNumbers_High_Low(int Number)
{
	if (Number <= 0)
	{
		return;
	}
	else
	{
		std::cout << Number << std::endl;
		RecNumbers_High_Low(Number - 1);
	}
}

void RecNumbers_Low_High(int Number, int Current)
{	
	if (Current > Number)
	{
		return;
	}
	else
	{
		std::cout << Current << std::endl;
		RecNumbers_Low_High(Number, Current + 1);
	};
}