// Elle Grace Jen
// CS-41-61730
// Graph List
// 4/14/2019
#include<iostream>
using namespace std;

class Node
{
public:
	char data;
	Node* next;
	Node(char Label, Node* NextPtr)
	{
		data = Label;
		next = NextPtr;
	}
};
class Edge
{
public:
	Node* A;
	Node* B;
	bool ToA;
	bool ToB;
	double weight;
	Edge(Node* First, Node* Second, bool ToFirst, bool ToSecond, double eWeight)
	{
		A = First;
		B = Second;
		ToA = ToFirst;
		ToB = ToSecond;
		weight = eWeight;
	}
};
class Graph
{
public:
	Node** nodes;
	Edge** edges;
	Graph(Node** theseNodes, Edge** someEdges)
	{
		nodes = theseNodes;
		edges = someEdges;
	}
};
class LList
{
public:
	LList()
	{
		head = nullptr;
		primary = nullptr;
		MaxSize = 10;
		EdgeCount = 0;
		count = 0;
	}
	Node* head;
	Edge* primary;
	int MaxSize;
	int EdgeCount;
	int count;
	Node** vertexArray = new Node*[MaxSize];
	Edge** edgeArray = new Edge*[MaxSize];

	void AddNode(char identity)
	{
		Node* node = new Node(identity, nullptr);
		if (head == nullptr)
		{
			head = node;
			return;
		}
		if (identity < head->data)
		{
			node->next = head;
			head = node;
			return;
		}
		Node* temp;
		for (temp = head; temp->next != nullptr; temp = temp->next)
			if (identity < temp->next->data)
				break;

		node->next = temp->next;
		temp->next = node;
	}
	void AddEdge(double EdgeWeight, char first, char second)
	{
		int firstIndex = getIndex(first);
		int secondIndex = getIndex(second);
		head = vertexArray[firstIndex];
		AddNode(second);
		head = vertexArray[secondIndex];
		AddNode(first);
		Edge* edge = new Edge(vertexArray[firstIndex], vertexArray[secondIndex], true, true, EdgeWeight);
		(edgeArray)[EdgeCount] = edge;
		EdgeCount++;
	}
	void Print()
	{
		Node* temp;
		cout << "List:" << endl;
		for (temp = head; temp != nullptr; temp = temp->next)
			cout << " " <<  temp->data << endl;
	}
	void getPoints()
	{
		char Label;
		char adjacentNode;
		char edgeNode;
		double edgeWeight;
		cout << "Please enter the desired number of points." << endl;
		cin >> MaxSize;
		cout << "Label the points." << endl;
		for (int i = 0; i < MaxSize; i++)
		{
			cin >> Label;
			Node* temp = new Node(Label, nullptr);
			(vertexArray)[count] = temp;
			count++;
		}
		cout << "We will now form edges. Enter two points at a time." << endl;
		cout << "Following the points enter a weight for the edge." << endl;
		cout << "Enter '$' as Point 1 to stop creating edges." << endl;
		do	{
			cout << "Point 1:";
			cin >> adjacentNode;
			if (adjacentNode != '$')
			{
				cout << "Point 2:";
				cin >> edgeNode;
				cout << "Edge Weight: ";
				cin >> edgeWeight;
				AddEdge(edgeWeight, adjacentNode, edgeNode);
			}
		} while (adjacentNode != '$');
	}
	int getIndex(char Point)
	{
		for (int i = 0; i < MaxSize; i++)
		{
			if (vertexArray[i]->data == Point)
			{
				return i;
			}
		}
	}
	void ListEdges()
	{
		cout << "The edges are as follows:" << endl;
		for (int i = 0; i < EdgeCount; i++)
		{
			cout << endl << "Edge: " << (edgeArray[i]->A->data) << (edgeArray[i]->B->data);
			cout << " Weight: " << edgeArray[i]->weight;
		}
	}
};
int main()
{
	LList TestGraph; 
	TestGraph.getPoints();
	TestGraph.ListEdges();
}
