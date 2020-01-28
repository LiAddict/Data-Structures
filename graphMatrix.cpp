// Elle Grace Jen
// CS-41-61730
// Graph Matrix
// 4/14/2019
#include <iostream>
#include <sstream>
using namespace std;

class GraphMatrix
{
public:
	int MaxSize;
	char* labelArray;
	double* edgeArray;
	int labelCount = 0;
	void AddEdge(double weight, char firstPoint, char secondPoint)
	{
		int firstIndex;
		int secondIndex;
		firstIndex = getIndex(firstPoint);
		secondIndex = getIndex(secondPoint);
		edgeArray[firstIndex, secondIndex] = weight;
	}
	int getIndex(char identity)
	{
		for (int i = 0; i < MaxSize; i++)
		{
			if (labelArray[i] == identity)
			{
				return i;
			}
		}
		return -1;
	}
	void getPoints()
	{
		char Label;
		char adjacentNode;
		char edgeNode;
		double edgeWeight;
		cout << "Please enter the desired number of points." << endl;
		cin >> MaxSize;
		labelArray = new char[MaxSize];
		edgeArray = new double[MaxSize, MaxSize];
		cout << "Label the points." << endl;
		for (int i = 0; i < MaxSize; i++)
		{
			cin >> Label;
			labelArray[labelCount] = Label;
			labelCount++;
		}
		cout << "We will now form edges. Enter two points at a time." << endl;
		cout << "Following the points enter a weight for the edge." << endl;
		cout << "Enter '$' as Point 1 to stop creating edges." << endl;
		do {
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
			else
			{
				break;
			}
		} while (adjacentNode != '$');
		
	}
	void ListEdges()
	{
		for (int i = 0; i < MaxSize; i++)
		{
			for (int j = 0; j < MaxSize; j++)
			{
				cout << "Edge: " << labelArray[i] << labelArray[j];
				cout << " Weight: " << edgeArray[i, j] << endl;
			}
		}
	}
};
int main()
{
	GraphMatrix testMatrix;
	testMatrix.getPoints();
	testMatrix.ListEdges();
}
