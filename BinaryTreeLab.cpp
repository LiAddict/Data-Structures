//; Krista Ghazaleh
//; CS-41-61730
//; BinaryTreeLab - including both print and traversals
//; 3/17/2019
#include "pch.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <sstream>
#include <cstdio>
#include <cctype>
#define MAX_SIZE 15
#define ROOT 0
// define values that will not change
using namespace std;

class BinaryTree
{
private:
	int *treeArray = new int[MAX_SIZE];
	int count = 0;
public:
	bool insert(int data);
	// will insert data at the count position
	void preorder(int root);
	// will print before calling left and right
	void inorder(int root);
	// will call left, print, then call right
	void postorder(int root);
	// will call left, right, and then print
	void print();
};

// define each function
bool BinaryTree::insert(int data)
{
	if (count < 15)
	{
		treeArray[count] = data;
		count++;
		return true;
	}
	else
	{
		return false;
	}
}

void BinaryTree::preorder(int root)
{
	if (root <= 15)
		// print number of nodes, not anything more
	{
		cout << treeArray[root] << ", ";
	}
	if (root <= 6)
		// number of right nodes
	{
		preorder((2 * root) + 1);
	}
	if (root <= 15)
		// number of nodes
	{
		inorder((2 * root) + 2);
	}
}

void BinaryTree::inorder(int root)
{
	if (root <= 6)
	{
		inorder((2 * root) + 1);
	}
	if (root <= 15)
	{
		cout << treeArray[root] << ", ";
		inorder((2 * root) + 2);
	}
}

void BinaryTree::postorder(int root)
{
	if (root <= 6)
	{
		postorder((2 * root) + 1);
	}
	if (root <= 15)
	{
		postorder((2 * root) + 2);
		cout << treeArray[root] << ", ";
	}
}
void BinaryTree::print()
	// print as inserted
{
	cout << endl << "Tree Values:" << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << treeArray[i] << ", ";
	}
}
int main()
{
	BinaryTree treeArr;
	int holdVal;
	cout << "Enter 15 values: " << endl;
	for (int i = 0; i < 15; i++)
	{
		cin >> holdVal;
		treeArr.insert(holdVal);
	}
	cout << "preOrder:" << endl;
	treeArr.preorder(ROOT);
	cout << endl << "inOrder:" << endl;
	treeArr.inorder(ROOT);
	cout << endl << "postOrder" << endl;
	treeArr.postorder(ROOT);
	treeArr.print();
}