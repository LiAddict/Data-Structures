// Krista Ghazaleh
// CS-41-61730
// Lab 8-Binary Search Algorithm
// 2/24/19

#include "pch.h"
#include <iostream>
#include<cstdlib>
using namespace std;

class BinarySearch
{	
	// functions for binary search
public:
	int getSearch()
	{
		int searchInt;
		cout << "Enter an integer to search for." << endl;
		cin >> searchInt;
		return searchInt;
	}
	int searchArray(int **vArr, int sFor)
	{
		// accepts an integer array of size 10
		int firstI = 0;
		int lastI = 9;
		while (firstI <= lastI)
			// uses differences to continue the loop
		{
			int middleI = (firstI + lastI) / 2;
			// finds middle index
			if (sFor > (*vArr)[middleI])
			{ // compares search value with data at index
				firstI = middleI - 1;
				// if greater than, search upper half
			}
			else if (sFor < (*vArr)[middleI])
			{	// if less than, search lower half
				lastI = middleI - 1;
			}
			else
			{	// if equal, return index
				return middleI;
			}
			// keep splitting through while until equal to
		}
		return -(firstI + 1);
		// if not found return -1
	}
};
class handleArray
{
	// holds array handling functions
public:
	int selectionSort(int **sArr)
	{ // switch larger with smaller
		int smallIndex;
		int smallNumb;
		for (int i = 0; i < 10; ++i)
		{
			for (int n = i + 1; n < 10; ++n)
			{
				if ((*sArr)[n] < (*sArr)[i])
				{
					smallIndex = n;
					smallNumb = (*sArr)[n];
					(*sArr)[smallIndex] = (*sArr)[i];
					(*sArr)[i] = smallNumb;
				}
			}
		}
		return (*sArr)[10];
	}
	int fillArray(int **userArray)
	{
		int i = 0;
		//; functions as index address
		cout << "Enter 10 integers for sorting." << endl;
		
		while (i < 10)
		{
			cin >> (*userArray)[i];
			++i;
		};
		return (*userArray)[10];
	}
	void printArray(int **myArr)
	{
		int i = 0;
		cout << "Your sorted array is:" << endl;

		while (i<10)
		{
			cout << (*myArr)[i] << endl;
			i++;
		}
	}
};

int main()
{ 
	handleArray aSort;
	int *bArray;
	int holdSearch;
	int retIndex;
	bArray = new int[10];
	aSort.fillArray(&bArray);
	aSort.selectionSort(&bArray);
	aSort.printArray(&bArray);
	BinarySearch bSearch;
	holdSearch = bSearch.getSearch();
	retIndex = bSearch.searchArray(&bArray, holdSearch);
	cout << "Your index is:" << endl << retIndex;
}

