#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

template <typename T> class Node
{
	//; makes node of general data type
public:
	T data;
	Node<T> *next;
	Node(T aData, Node<T> *aNext)
	{
		data = aData;
		next = aNext;
	}
	T getData()
	{
		return data;
	}
	Node<T> *Next()
	{
		return next;
		//return link
	}
	void setNext(Node<T> *aNext)
	{
		next = aNext;
		//set link
	}
};
template <typename T> class LList {
public:
	Node<T> *head;
	//head pointer
	LList()
	{
		head = nullptr;
		// point to nothing, find out what to point to
	}
	bool Create(T data)
		// function will add a new node at end, parameter insert data
	{
		Node<T> *newNode = new Node<T>(data, nullptr);
		// object
		Node<T> *tmp = head;
		if (tmp != nullptr)
			// checks for last node
		{
			// finds last node
			while (tmp->Next() != nullptr)
			{
				tmp = tmp->Next();
				// move forward
			}
			tmp->setNext(newNode);
			// point to new node
			return true;
		}
		else
		{
			head = newNode;
			return true;
			// no other nodes, new node becomes head
		}
	}
	bool InsertAtIndex(int index, T data)
		// will create a node at a certain index
	{
		Node<T> *newNode = new Node<T>(data, nullptr);
		Node<T> *tmp = head;
		if (index == 0)
		{
			head = newNode;
			head->setNext(tmp);
			return true;
		}
		while (index > 0)
		{
			tmp = tmp->Next();
			index--;
		}
		tmp->setNext(newNode);
		return true;

	}
	void Delete(T data)
		// will delete node holding specific data from list
		// searches through data (not index)
	{
		Node<T> *tmp = head;
		// temp pointer 
		if (tmp == nullptr)
			// checks for no nodes
		{
			return;
		}
		if (tmp->Next() == nullptr && tmp->getData() == data)
			//checks if end of list
		{
			delete tmp;
			head = nullptr;
		}
		else {
			// must change prev node pointer
			// point to node after deleted
			Node<T> *prev;
			do {
				// while there are nodes left
				if (tmp->getData() == data)
					break;
				tmp = tmp->Next();
			} while (tmp != nullptr);
			prev->setNext(tmp->Next());
			delete tmp;
			//delete the node
		}
	}
	T get(int index)
	{  // makes list indexable by traversing through
		// returns data at index by decrementing count
		// "index" is a counter
		Node<T> *tmp = head;
		while (index > 0)
		{
			tmp = tmp->Next();
			index--;
		}
		return tmp->getData();
	}
	void deleteAtIndex(int index)
	{
		Node<T> *tmp = head;
		Node<T> *del = tmp;
		if (index == 0)
		{
			head = tmp->Next();

		}
		while (index > 0)
		{
			tmp = tmp->Next();
			index--;
		}
		delete del;
	}
	bool CheckList()
	{
		Node<T> *tmp = head;
		if (tmp == nullptr)
			// checks for no nodes
		{
			return true;
		}
		else
			return false;
	}
	void Print()
	{
		// will print list if needed
		Node<T> *tmp = head;
		while (tmp != nullptr)
		{
			cout << tmp->getData() << endl;
			tmp = tmp->Next();
		}
	}
};
template <typename T> class Stack : public LList<T>
{
	LList<T> sList;
public:
	void isEmpty()
	{
		//checks for list/stack nodes
		sList.CheckList();
	}

	bool push(T entry)
	{
		// creates entry to push to top of stack/list
		if (sList.InsertAtIndex(0, entry) == true)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	T pop()
	{
		// returns first node/ top of stack
		// deletes node at the spot
		int PopAt = 0;
		T val = sList.get(PopAt);
		sList.deleteAtIndex(PopAt);
		return val;

	}
	T peek(int peekAt)
	{
		T val = sList.get(peekAt);
		return val;
	}
};
template <typename T> class ReversePolishNotation : public Stack<T>
{
public:
	Stack<double> thisStack;
	string getString()
	{
		string expression;
		cout << "Enter ints and operands. Separate with space, follow with '='." << endl;
		getline(cin, expression);
		return expression;
	}
	bool CalculateExpression(string rpnExpression)
	{
		double value1;
		double value2;
		double result;
		int i = 0;
		int n = 0;
		size_t stringLength = rpnExpression.length();
		stringstream stringstream(rpnExpression);
		while (n <= stringLength)
		{	// index string
			switch (rpnExpression[i])
			{
			case '+':
				value1 = thisStack.pop();
				value2 = thisStack.pop();
				result = value2 + value1;
				thisStack.push(result);
				break;
			case '-':
				// check for negative vs minus operator
				if (rpnExpression[i + 1] == ' ')
				{
					value1 = thisStack.pop();
					value2 = thisStack.pop();
					result = value2 - value1;
					thisStack.push(result);
					break;
				}
				else
				{
					stringstream >> value1;
					thisStack.push(value1);
					break;
				}

			case '*':
				value1 = thisStack.pop();
				value2 = thisStack.pop();
				result = value2 * value1;
				thisStack.push(result);
				break;
			case '/':
				value1 = thisStack.pop();
				value2 = thisStack.pop();
				if (value1 == 0)
				{
					cout << "Error: Division by zero" << endl;
					return false;
				}
				else
				{
					result = value2 / value1;
					thisStack.push(result);
					break;
				}
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
			case '.':
				stringstream >> value1;
				thisStack.push(value1);
				break;
			case ' ':
			case '=':
				break;
			default:
				break;
			}
			while ((i < stringLength - 1) && rpnExpression[i] != ' ')
			{
				i++;
				n++;
			}
			if (i < stringLength)
			{
				i++;
				n++;
			}
			n++;
		}

		return true;
	}
	void getResult()
	{
		cout << "Your result is: " << endl;
		cout << thisStack.pop() << endl;
	}
	bool countOps(string rpnstring)
	{
		stringstream stringstream(rpnstring);
		double rpnOperand;
		char rpnOperate;
		int operandCount = 0;
		int operateCount = 0;
		size_t stringLength = rpnstring.length();

		// hold number of operands and operators
		int i = 0;
		int n = 0;
		// counts index of the spaces

		while (n < stringLength)
		{
			switch (rpnstring[i])
			{
			case '+':
			case '*':
			case '/':
				stringstream >> rpnOperate;
				operateCount++;
				break;
			case '-':
				if (rpnstring[i + 1] == ' ')
				{
					stringstream >> rpnOperate;
					operateCount++;
					break;
				}
				else
				{
					stringstream >> rpnOperand;
					operandCount++;
					break;
				}
				break;
			case '=':
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '.':
			case '0':
				stringstream >> rpnOperand;
				operandCount++;
				break;
			case ' ':
				break;
			}
			while ((i < stringLength - 1) && rpnstring[i] != ' ')
			{
				i++;
			}
			n++;
			if (i < stringLength - 1)
			{
				i++;
				n++;
			}
		}
		if (operandCount == operateCount + 1)
		{
			return true;
		}
		else
		{
			if (operandCount < operateCount + 1)
			{
				cout << "Error: Too many operators" << endl;
			}
			else if(operandCount > operateCount + 1)
			{
				cout << "Error: Too many operands" << endl;
			}

			return false;
		}
	}
};
int main()
{
	string RPN;
	ReversePolishNotation<double> rpnEx;
	LList<int> list;
	do
	{
		RPN = rpnEx.getString();
		if (rpnEx.countOps(RPN) == true)
		{
			list.Print();
			if (rpnEx.CalculateExpression(RPN) == true)
			{
				rpnEx.getResult();
			}
		}
	} while (RPN[0] != '0');
}

