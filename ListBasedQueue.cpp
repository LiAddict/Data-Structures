// Elle Grace Jen
// CS-41-61730
// List Based Queue
// 4/21/2019
#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node(int Entry, Node* NextPtr)
	{
		data = Entry;
		next = NextPtr;
	}
};
class Queue
{
public:
	Queue()
		// initialize data
	{
		Count = 0;
		front = nullptr;
		back = nullptr;
	}
	int Count;
	Node* front;
	Node* back;

	void EnQueue(int input)
	{
		Node* tmp;
		tmp = front;
		if (front == nullptr)
		{
			front = new Node(input, nullptr);
			back = front;
			Count++;
			return;
		}
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(input, nullptr);
		back = tmp->next;
		Count++;
		return;
	}
	int DeQueue()
	{
		Node* tmp;
		int holder;
		tmp = front;
		if (Count == 0) 
		{
			cout << "Error: Queue is empty. Returning 0." << endl;
			return 0;
		}
		holder = tmp->data;
		if (front->next == nullptr)
		{
			front = nullptr;
			// delete the only node
		}
			front = tmp->next;
			delete tmp;
			Count--;
			return holder;
	}
	bool IsEmpty()
	{
		if (Count == 0)
		{
			cout << "Count is zero." << endl;
			return true;
		}
		else if (Count > 0)
		{
			cout << "Count is " << Count << endl;
			return false;
		}
	}
};
int main()
{
	Queue myQueue;
	int output;
	// test for functionality by calling functions
	myQueue.EnQueue(5);
	myQueue.EnQueue(4);
	myQueue.IsEmpty();
	output = myQueue.DeQueue();
	cout << output << endl;
	output = myQueue.DeQueue();
	cout << output << endl;
	output = myQueue.DeQueue();
	cout << output << endl;
	myQueue.IsEmpty();
}
