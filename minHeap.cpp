// Krista Ghazaleh
// CS-41-61730
// Min Heap
// 4/28/2019
#include <iostream>
#include <cstdlib> 
#include <sstream>
#include <cstdio>
#define MAX_SIZE 15
#define ROOT 0
using namespace std;
class heap
{
private:
	int* treeArray = new int[MAX_SIZE];
	int count = 0;
	void swap(int parent, int child)
	{
		int tmp;
		tmp = treeArray[parent];
		treeArray[parent] = treeArray[child];
		treeArray[child] = tmp;
	}
public:
	void Add(int data)
	{
		int index;
		treeArray[count] = data;
		index = count;
		count++;
		while (treeArray[index] < treeArray[index/2])
		{
			swap(index, index/2);
			index /= 2;
		}
	}
	int Delete(void)
	{
		int root;
		int smallest;
		root = treeArray[0];
		smallest = treeArray[1];
		for (int i = 1; i < count; i++)
		{
			if (treeArray[i] < smallest)
			{
				smallest = treeArray[i];
			}
		}
		treeArray[0] = smallest;
		count--;
		return root;
	}
	void print()
		// print as inserted
	{
		cout << endl << "Tree Values:" << endl;
		for (int i = 0; i < count; i++)
		{
			cout << treeArray[i] << ", ";
		}
	}
};
int main()
{
	heap myheap;
	int input;
	int root;
	cout << "Enter values to the heap." << endl;
	for (int i = 0; i < 15; i++)
	{
		cin >> input;
		myheap.Add(input);
	}
	myheap.print();
	root = myheap.Delete();
	myheap.print();
	cout << "Prior Root: " << root;
	root = myheap.Delete();
	myheap.print();
	cout << "Prior Root: " << root;
	
}
