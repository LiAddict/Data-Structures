//; Krista Ghazaleh
//; CS-41-61730
//; Program 3
//; 4/7/2019

#include "pch.h"
#include <iostream>
#include <sstream>
using namespace std;

class Node
{
	// makes node of general data type for sorting of strings or ints
public:
	string nameData;
	int weightData;
	// data member held in each node
	Node *left;
	Node *right;
	// two self refrential pointers
	// two node pointers
	Node(string ndata, int wdata)
		/* the constructor sets up the long term stored data contained in each node
		and this includes the link pointers initialized to null*/
	{
		nameData = ndata;
		weightData = wdata;
		left = nullptr;
		right = nullptr;
	}
};

class BinarySearchTree
	/* THE BINARYSEARCHTREE CLASS contains the functions for working with the 
	binary search tree that sorts based on alphebetical order
	by name with left links containing names beginning with letters
	closer towards the beginning of the alphabet and right
	containing those closer to the end*/
{
private:
	/* certain data is made private. This is for encapsulation 
	purposes to avoid unwanted changes, the main function does not need to
	directly access this data or these functions and functions are
	called indirectly through other functions which take no parameters
	for simplification, ease, and reduction of error*/
	Node *head;
	//head pointer
	Node *searchNode;
	Node * lowWeight;
	int leaves;
	void Insert(string newName, int newWeight, Node *start)
		/* THE INSERT FUNCTION creates and adds a new node to the Binary Search Tree
		based on sorting the newName data. The weight comes with the name data
		in an ordered pair fashion contained within the node. The start node is necessary as
		it is the the first node in each subtree where this function compares
		with the children of each node by calling each child recursively.*/
	{
		if (head == nullptr)
			/* This conditional statement checks for an existing head node. If the
			head does not yet exist the new node is created with the parameter data
			and becomes the new head*/
		{
			head = new Node(newName, newWeight);
			return;
		}
		if ((newName < (start->nameData)) && (start->left != nullptr))
			/*check for lower name in alphabet in comparison to subparent.
			Also checks if a child is present on that side. If data is alphabetically
			lower and a child already exists, compare to that child by recalling function
			with the child node inserted*/
		{
			Insert(newName, newWeight, start->left);
		}
		else if ((newName < start->nameData) && (start->left == nullptr))
			/*if the name is lower in the alphabet and the parent has no child
			the new node can be created and inserted as the new child*/
		{
			start->left = new Node(newName, newWeight);
			return;
		}
		else if ((newName >= start->nameData) && (start->right != nullptr))
			/* Same condition except for those higher in the alphabet so the check
			goes for those on the right. If the same name is entered, the new data moves
			and is compared to the right as well.*/
		{
			Insert(newName, newWeight, start->right);
		}
		else if ((newName >= start->nameData) && (start->right == nullptr))
			/* for a value higher in the alphebet, if there is no child for the parent node,
			create the new node and make it the child.*/
		{
			start->right = new Node(newName, newWeight);
			return;
		}
		else
		{
			return;
		}
	}
	/* DEPTH FIRST SEARCHES go through each node and print the nodes in an
	order depending on the search. These functions, PreOrder, InOrder, and
	PostOrder are private encapsulated data each called by the public 
	Print function. Each search will be called until the end of each 
	direction is reached which is marked by a null pointer.*/
	void PreOrder(Node *root)
		/* PREORDER recursively calls itself to search every node in the tree.
		The print comes first before the other searches, the order is VLR. Print, 
		Left, Right.*/
	{
		cout << root->nameData << ", " << root->weightData << endl;
		if (root->left != nullptr)
		{
			PreOrder(root->left);
		}
		if (root->right != nullptr)
		{
			PreOrder(root->right);
		}
	}
	void inOrder(Node *root)
		/* INORDER recursively calls itself to search every node in the tree.
		The print comes after before the left search, the order is LVR.
		Left, Print, Right.*/
	{
		if (root->left != nullptr)
		{
			inOrder(root->left);
		}
		cout << root->nameData << ", " << root->weightData << endl;
		if (root->right != nullptr)
		{
			inOrder(root->right);
		}
	}
	void PostOrder(Node *root)
		/* POSTORDER recursively calls itself to search every node in the tree.
		The print comes after before both searches, the order is LRV.
		Left, Right, Print*/
	{
		if (root->left != nullptr)
		{
			PostOrder(root->left);
		}
		if (root->right != nullptr)
		{
			PostOrder(root->right);
		}
		cout << root->nameData << ", " << root->weightData << endl;
	}
	int determineHeight(Node *start)
		/*DETERMINEHEIGHT FUNCTION recursively calls through each child
		of each node and finds the height of each subtree, returning the
		larger values since each layer has either a left or right side
		which can vary depending on the data. The largest is returned and
		which will effectively give the height of the tree since each larger 
		subtree will add one to the height by providing an extra layer.
		This function is privately accessed by the getHeight function*/
	{
		int leftHeight;
		int rightHeight;
		if (start == nullptr)
		{
			return -1;
			// returns -1 if no treenodes exist
		}
		else
		{
			leftHeight = determineHeight(start->left);
			rightHeight = determineHeight(start->right);
			if (leftHeight > rightHeight)
			{
				return (leftHeight + 1);
			}
			else
			{
				return(rightHeight + 1);
			}
		}
	}
	void countLeaves(Node *root)
		/*THE COUNTLEAVES FUNCTION uses recursion to check how many
		children are not parents where both their left and right
		links are nullptr, point to nothing*/
	{
		if (root->left != nullptr)
		{
			countLeaves(root->left);
		}
		if (root->right != nullptr)
		{
			countLeaves(root->right);
		}
		if (root->right == nullptr && root->left == nullptr)
			/*The number of leaves is stored in a class variable, 
			leaves and each time a child is found that is not a parent
			itself, leaves is incremented by one more leaf*/
		{
			leaves++;
		}
	}
	void Search(Node *root, string nData)
		/* THE SEARCH FUNCTION privately accessed by the getSearch
		function uses recursion to check each node's child for a specific
		name data value. If found the node is stored as the searchNode
		which can be retrieved after the function finishes executing*/
	{
		if (root->nameData == nData)
		{
			searchNode = root;
		}
		if (root->left != nullptr)
		{
			Search(root->left, nData);
		}
		if (root->right != nullptr)
		{
			Search(root->right, nData);
		}
	}
	void FindWeight(Node *root)
		/* THE FINDWEIGHT FUNCTION is privately accessed by the getLowestWeight
		function and uses recursion to check each node's child's weight value.
		The node with the lowest weight is stored as the lowWeight node. If a 
		lowWeight node does not yet exist the current node is set to lowWeight
		and the weight value of each node is compared to the current lowWeight
		node. If the next current node's weight is lower than the lowWeight node, 
		the current node is set as the new lowWeight node*/
	{
		if (lowWeight == nullptr)
		{
			lowWeight = root;
		}
		if (root->weightData < lowWeight->weightData)
		{
			lowWeight = root;
		}
		if (root->left != nullptr)
		{
			FindWeight(root->left);
		}
		if (root->right != nullptr)
		{
			FindWeight(root->right);
		}
	}
public:
	BinarySearchTree()
		/* BINARYSEARCHTREE constructor made public to allow creation of the
		object outside of the class. Contains the head node, searchNode,
		and node to hold the lowest weight each initialized to nullptr.*/
	{
		head = nullptr;
		searchNode = nullptr;
		lowWeight = nullptr;
		// point to nothing, find out what to point to
	}
	void Add(string nameString, int weightInt)
		/* ADD FUNCTION accesses the private insert function to
		add a starting node value, the root*/
	{
		Insert(nameString, weightInt, head);
	}
	void Print()
	/* PRINT FUNCTION privately accesses the depth first searches to print
	execute and print each traversal with the root as the 
	startig node*/
	{
		cout << endl << "PreOrder traversal: " << endl;
		PreOrder(head);
		cout << endl << "InOrder traversal: " << endl;
		inOrder(head);
		cout << endl << "PostOrder traversal: " << endl;
		PostOrder(head);
	}
	void getHeight()
		/* GETHEIGHT FUNCTION calls the determine height function and prints
		the results of the function as long as at least one 
		treenode exists*/
	{
		int height;
		height = determineHeight(head);
		if (height != -1)
		{
			cout << "Height: " << height << endl;
		}
		else
		{
			cout << "Root is null." << endl;
		}
	}
	
	void getLeaves()
		/* GETLEAVES FUNCTION calls the countleaves function and
		prints the leaves variable which was used by
		countleaves to store the number of leaves*/
	{
		countLeaves(head);
		cout << "Leaves: " << leaves << endl;
	}
	void getSearch()
		/* GETSEARCH FUNCTION retrieves data to search for and calls the search function 
		with the search data and root start node entered as the parameters.
		The function then prints the result of the search*/
	{
		string searchName;
		cout << "Please enter a name to search for." << endl;
		cin >> searchName;
		Search(head, searchName);
		if (searchNode != nullptr)
		{
			cout << "You entered: " << searchName << endl;
			cout << "The weight is: " << searchNode->weightData << endl;
		}
		else
		{
			cout << "Name not found." << endl;
		}
	}
	void getLowestWeight()
		/*GETLOWESTWEIGHT FUNCTION calls findWeight with the root
		as the starting node and then prints the result which was stored
		as the lowWeight node.*/
	{
		FindWeight(head);
		cout << "Lowest Weight:" << endl;
		cout << lowWeight->nameData << ", " << lowWeight->weightData;
	}
	void getFirstName()
		/*GETFIRSTNAME FUNCTION creates a temporary node iterator that
		traverses through the left side of the tree since the lowest names on 
		the alphabet are stored to the left. The function moves through the
		left until the end nullptr is reached and prints the name of the
		far left node which was stored as tmp.*/
	{
		Node *tmp = head;
		while (tmp->left != nullptr)
		{
			tmp = tmp->left;
		}
		cout << endl << "The first name in alphebetical order is: " << tmp->nameData;
	}
};

int main()
{
	BinarySearchTree Tree;
	// object
	int intEntry;
	string strEntry;
	// variables hold data entry
	cout << "Please enter 15 names and their respective weights to be sorted." << endl;
	for (int i = 0; i < 15; i++)
		/* loop through taking user input and then directly inserting the input
		as the parameters of a function call within the loop to get data 15 times.*/
	{
		cout << "Name: ";
		cin >> strEntry;
		cout << "Weight: ";
		cin >> intEntry;
		Tree.Add(strEntry, intEntry);
	}
	// call each smaller data handling function after tree is created
	Tree.Print();
	Tree.getHeight();
	Tree.getLeaves();
	Tree.getSearch();
	Tree.getLowestWeight();
	Tree.getFirstName();
}
/* A SAMPLE OUTPUT:
Please enter 15 names and their respective weights to be sorted.
Name: Jim
Weight: 150
Name: Tom
Weight: 212
Name: Michael
Weight: 174
Name: Abe
Weight: 199
Name: Richard
Weight: 200
Name: April
Weight: 117
Name: Claire
Weight: 124
Name: Bobby
Weight: 109
Name: Bob
Weight: 156
Name: Kevin
Weight: 145
Name: Jason
Weight: 182
Name: Brian
Weight: 150
Name: Chris
Weight: 175
Name: Steven
Weight: 164
Name: Annabelle
Weight: 99

PreOrder traversal:
Jim, 150
Abe, 199
April, 117
Annabelle, 99
Claire, 124
Bobby, 109
Bob, 156
Brian, 150
Chris, 175
Jason, 182
Tom, 212
Michael, 174
Kevin, 145
Richard, 200
Steven, 164

InOrder traversal:
Abe, 199
Annabelle, 99
April, 117
Bob, 156
Bobby, 109
Brian, 150
Chris, 175
Claire, 124
Jason, 182
Jim, 150
Kevin, 145
Michael, 174
Richard, 200
Steven, 164
Tom, 212

PostOrder traversal:
Annabelle, 99
Bob, 156
Chris, 175
Brian, 150
Bobby, 109
Jason, 182
Claire, 124
April, 117
Abe, 199
Kevin, 145
Steven, 164
Richard, 200
Michael, 174
Tom, 212
Jim, 150
Height: 6
Leaves: 6
Please enter a name to search for.
Chris
You entered: Chris
The weight is: 175
Lowest Weight:
Annabelle, 99
The first name in alphebetical order is: Abe
*/