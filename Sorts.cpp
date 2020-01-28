// Elle Grace Jen
// CS-41-61730
// Lab 7-Sort
// 2/24/2019

#include "pch.h"
#include <iostream>
using namespace std;

class Sort
{
public:
	int bubbleSort(int **bArr)
	{ // traverse through from beginning to end
		int countSwitches = 0;
		for (int n = 0; n < 6; n++)
		{
			for (int x = 0; x < 5; x++)
			{
				if ((*bArr)[x] > (*bArr)[x + 1])
				{
					holdVal = (*bArr)[x];
					(*bArr)[x] = 0;
					(*bArr)[x] = (*bArr)[x + 1];
					(*bArr)[x + 1] = holdVal;
					holdVal = 0;
					++countSwitches;
				}
				if (countSwitches = 0)
				{
					n = 6;
				}
			}
		}
		cout << "Your ordered array is:" << endl;
		for (int j = 0; j < 6; ++j)
		{
			cout << (*bArr)[j] << endl;
		}
		return (*bArr)[6];
	}
	int insertionSort(int **iArr)
	{	// insert smallest at beginning
		for (int i = 1; i < 6; i++) 
		// i = 0 current smallest by default
		{
			int x = i;
			// i denotes current numb of elements
			// x can decrement from current i
			while (x > 0 && (*iArr)[x - 1] > (*iArr)[x]) 
			// cmp to prior elements
			{
				holdVal = (*iArr)[x];
				(*iArr)[x] = (*iArr)[x - 1];
				(*iArr)[x - 1] = holdVal;
				x--;
			}
		}
		cout << "Your ordered array is:" << endl;
		for (int j = 0; j < 6; ++j)
		{
			cout << (*iArr)[j] << endl;
		}
		return (*iArr)[6];
	}

	int selectionSort(int **sArr)
	{ // switch larger with smaller
		int smallIndex;
		int smallNumb;
		for (int i = 0; i < 6; ++i)
		{
			for (int n = i+1; n < 6; ++n)
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
		cout << "Your ordered array is:" << endl;
		for (int j = 0; j < 6; j++)
		{
			cout << (*sArr)[j] << endl;
		}
		return (*sArr)[6];
	}

	void swap(int i, int j, int **a)
	{ // called by quicksort to swap numbs
		int temp = (*a)[i];
		(*a)[i] = (*a)[j];
		(*a)[j] = temp;
	}

	void quicksort(int **arr, int left, int right) 
	{	// compares to pivot, moves smaller on left
		// moves larger to right
		int min = (left + right) / 2;

		int i = left;
		int j = right;
		int pivot = (*arr)[min];

		while (left < j || i < right)
		{
			while ((*arr)[i] < pivot)
				i++;
			while ((*arr)[j] > pivot)
				j--;

			if (i <= j) {
				// compares results of pivot comparison to
				// call swap as needed
				swap(i, j, arr);
				i++;
				j--;
			}
			else {
				// works recursively to create partitions
				// with new pivot each time
				if (left < j)
					quicksort(arr, left, j);
				if (i < right)
					quicksort(arr, i, right);
				return;
			}
		}
	}


	int mergeSort(int **mArr, int low, int high, int mid)
	{
		// will create smaller partitions, sort each 
		// and merge and sort them together until
		// merged entirely
			int i, j, k, pseudo[50];
			// pseudo array of max 50
			i = low;
			k = low;
			j = mid + 1;
			while (i <= mid && j <= high)
			{	// will allocate memory based on value
				// pseudo array used to create partitions
				if ((*mArr)[i] < (*mArr)[j])
				{
					pseudo[k] = (*mArr)[i];
					k++;
					i++;
				}
				else
				{
					pseudo[k] = (*mArr)[j];
					k++;
					j++;
				}
			}
			while (i <= mid)
			{	// will continue based on index
				// that changed based on value
				pseudo[k] = (*mArr)[i];
				k++;
				i++;
			}
			while (j <= high)
			{
				pseudo[k] = (*mArr)[j];
				k++;
				j++;
			}
			for (i = low; i < k; i++)
			{
				(*mArr)[i] = pseudo[i];
			}
			// will print each both sorted partitions
			// with the break points being a difference in sorted ints
			cout << "Your ordered array is:" << endl;
			for (int j = 0; j < 6; j++)
			{
				cout << (*mArr)[j] << endl;
			}
			return (*mArr[6]);
	}

	void recursiveMerge(int **rArr, int lowIndex, int highIndex)
	{
		if (lowIndex < highIndex)
		{	// works recursively to create partitions
			// will continue to call recursively until
			// indexes are equivalent
			int midIndex = (lowIndex + highIndex) / 2;
			recursiveMerge(rArr, lowIndex, midIndex);
			recursiveMerge(rArr, midIndex + 1, highIndex);
			mergeSort(rArr, lowIndex, highIndex, midIndex);
		}
		return;
	}
	int holdVal = 0;
	

};
int main()
{
	Sort TypeSort;
	int *sort;
	sort = new int[6];
	// takes user input
	cout << "Enter 6 random positive integers:" << endl;
	for (int i = 0; i < 6; i++)
	{
		cin >> sort[i];
	}
	// displays quicksort directly through main for simplification
	TypeSort.quicksort(&sort, 0, 5);
	cout << "Your ordered array is:" << endl;
	for (int j = 0; j < 6; j++)
	{
		cout << sort[j] << endl;
	}

}

