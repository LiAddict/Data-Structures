// Krista Ghazaleh
// CS-41-61730
// Assignment 4 - Hash
// 5/12/2019
#include<iostream>
#include<sstream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
// tablesize = 26
class Node
	/* class Node will hold each hash and the respective scope level,
	and data which is held by the var's node in the hash table.*/
{
public:
	string key;
	int hash;
	Node* next;
	int Level;
	int data;

	Node(int theHash, int theData, Node* NextPtr, int currentLevel, string k)
	{
		data = theData;
		hash = theHash;
		next = NextPtr;
		Level = currentLevel;
		key = k;
	}
};
class HashTable
	/*The HashTable class contains the hashtable, which is an array of size 26,
	and contains the hashing function and BORG functions that interact with the
	hash table. All data functions work only with integers.*/
{
	Node** vertexArray = new Node * [26];
public:
	void Create(int hash, int Level, string key)
		/* The Create function will take in a variable's hash value and the scope level
		at which the variable was created. The function creates a node that is stored at
		the index of the table located at hash. Thus, hash is the index. The data value is
		preset to zero during the insert, and is changed in the InsertData function.*/
	{
		Node* hashNode = new Node(hash, 0, nullptr, Level, key);
		if (vertexArray[hash] == nullptr)
		{
			vertexArray[hash] = hashNode;
		}
		else
		{
			Node* tmp = vertexArray[hash];
			while (tmp->next != nullptr)
			{
				tmp = tmp->next;
			}
			tmp->next = hashNode;
		}
		return;

	}
	int Hash(string HashString)
		/* The Hash function evaluates the hash of a variable by taking the multiple of each
		char (equivalent to the ascii value) by their index, and adding them together. After
		taking the sum of each char multiplied by its respective index, the modulus is taken
		by the tablesize, which is 26.*/
	{
		int holdHash = 0;
		int i = 0;
		while (HashString[i] != '\0')
		{
			holdHash += (i * HashString[i]);
			i++;
		}
		holdHash = holdHash % 26;
		return holdHash;

	}
	void InsertData(int info, int hash, string Key)
		/*The InsertData function takes the data which is represented by info,
		and inserts it at the node's data member which is located at the index. The
		index is equivalent to the hash of the variable.*/
	{
		Node* tmp = vertexArray[hash];
		while (tmp->key != Key)
		{
			tmp = tmp->next;
		}
		tmp->data = info;
	}
	void Increment(int hash, string Key)
		/*The Increment function finds the node object located at the hash index and
		adds one to its data member.*/
	{
		Node* tmp = vertexArray[hash];
		while (tmp->key != Key)
		{
			tmp = tmp->next;
		}
		tmp->data++;
		return;
	}
	void Decrement(int hash, string Key)
		/*The Decrement function finds the node object located at the hash index and
		subtracts one from its data member.*/
	{
		Node* tmp = vertexArray[hash];
		while (tmp->key != Key)
		{
			tmp = tmp->next;
		}
		tmp->data--;
		return;
	}
	void Addition(int hash, int additive, string Key)
		/*The Addition function finds the node object located at the hash index and adds
		an indicated integer amount to its data member.*/
	{
		Node* tmp = vertexArray[hash];
		while (tmp->key != Key)
		{
			tmp = tmp->next;
		}
		tmp->data += additive;
		return;
	}
	void Subtraction(int hash, int subtractive, string Key)
		/*The Subtraction function finds the node object located at the hash index and subtracts
		an indicated integer amount from its data member.*/
	{
		Node* tmp = vertexArray[hash];
		while (tmp->key != Key)
		{
			tmp = tmp->next;
		}
		tmp->data += subtractive;
		return;
	}
	void Multiply(int hash, int multiple, string Key)
		/* The Muliply function finds the node object located at the hash index and multiplies
		its data member by an indicated integer amount.*/
	{
		Node* tmp = vertexArray[hash];
		while (tmp->key != Key)
		{
			tmp = tmp->next;
		}
		tmp->data *= multiple;
		return;
	}
	void Divide(int hash, int divisor, string Key)
		/*The Divide function finds the node object located at the hash index and divides its
		data member by an indicated integer amount.*/
	{
		Node* tmp = vertexArray[hash];
		while (tmp->key != Key)
		{
			tmp = tmp->next;
		}
		tmp->data /= divisor;
		return;
	}
	void Modulus(int hash, int modulo, string Key)
		/*The Modulus function finds the node object located at the hash index and takes the
		modulus of its data member by a specified divisor. The modulo represents the remainder.*/
	{
		Node* tmp = vertexArray[hash];
		while (tmp->key != Key)
		{
			tmp = tmp->next;
		}
		tmp->data %= modulo;
		return;
	}
	void Exponent(int hash, int power, string Key)
		/*The Exponent function fuinds the node object located at the hash index and multiplies
		its data member by itself a specified number of times using a for loop to count up to
		the power.*/
	{
		Node* tmp = vertexArray[hash];
		while (tmp->key != Key)
		{
			tmp = tmp->next;
		}
		for (int i = 0; i < power; i++)
		{
			tmp->data *= tmp->data;
		}
		return;
	}
	int Max(int firstHash, string firstKey, int secondHash, string secondKey)
		/*EC ADDITIONAL FUNCTION: The Max function compares the data members of the nodes located
		at two specified indexes or hashes, and returns the greater one. The function is instructed
		to handle when both members are equal or when at least one member does not exist.*/
	{
		Node* first = vertexArray[firstHash];
		while (first->key != firstKey)
		{
			first = first->next;
		}
		Node* second = vertexArray[secondHash];
		while (second->key != secondKey)
		{
			second = second->next;
		}
		if (first->data > second->data)
		{
			cout << "MAX IS " << first->data << endl;
			return first->data;
		}
		else if (first->data == second->data)
		{
			cout << "BOTH MEMBERS ARE EQUAL." << endl;
			return first->data;
		}
		else if (first->data < second->data)
		{
			cout << "MAX IS " << second->data << endl;
			return second->data;
		}
		else if (vertexArray[firstHash] == nullptr || vertexArray[secondHash] == nullptr)
		{
			cout << " MAX IS UNDEFINED." << endl;
			return 0;
		}
		return 0;
	}
	void Print(int hash, int current, string Key)
		/*The Print function checks for a node at the specified hash/index and prints out the
		data. Will check current level and compare to level in the table.
		Indicates if there is no node at the hash/index or if the variable is undefined
		or not in scope.*/
	{
		Node* tmp = vertexArray[hash];
		if (vertexArray[hash] == nullptr)
		{
			cout << " IS UNDEFINED" << endl;
			return;
		}
		while (tmp->key != Key)
		{
			tmp = tmp->next;
		}
		if (vertexArray[hash] != nullptr && tmp->Level <= current)
		{
			cout << " IS " << tmp->data << endl;
			return;
		}
		else
		{
			cout << " IS UNDEFINED" << endl;
			return;
		}
	}
	void initializeArray()
		/* the initialize array function uses a for loop to initialize each table value to
		nullptr to allow for ease in applying conditional statements. This initialization will
		also clear the table to prepare for compiling a separate BORG source (.txt) file.*/
	{
		for (int i = 0; i < 26; i++)
		{
			vertexArray[i] = nullptr;
		}
		return;
	}
};

class BORG
{
public:
	HashTable getHash;
	/*this instance of the HashTable class allows access to its member functions*/
	int scopeLevel;
	BORG()
	{
		scopeLevel = 0;
	}
	/*scope initialized to zero*/
	void Command(string filename)
		/*The Command function takes in a filename, and opens a file to fstream in each string
		that is separated by a whitespace. The while loop will keep grabbing commands and use
		conditional statements to decide which line of events to use depending on the string.*/
	{
		string key;
		/*holds variable/key*/
		ifstream inFile;
		/*instance of ifstream*/
		inFile.open(filename);
		/*open the file to be used*/
		string command;
		/*holds commands*/
		string input;
		/*holds subjects used by the commands*/
		int holdHash = 0;
		/*holds the hashes of variables*/
		int data;
		/*holds data to insert or manipulate depending on commands*/
		int holdMax = 0;
		/*used specifically by the max function*/
		while (!inFile.eof())
			/*keep looping until end of file*/
		{
			inFile >> command;

			if (command == "START")
				/*increase scope level*/
			{
				scopeLevel++;
			}
			else if (command == "FINISH")
				/*marks the end of the scope, decrements scope level*/
			{
				scopeLevel--;
			}
			else if (command == "COM")
			{
				/*comment is streamed in and ignored as a command.*/
			}
			else if (command == "VAR")
				/*checks for variable declaration and hashes/inserts variable/node
				in hashtable with the current level before inserting the data*/
			{
				// 1) get variable
				inFile >> input;
				key = input;
				// 2) hash variable
				holdHash = getHash.Hash(input);
				// 3) create the node at index
				getHash.Create(holdHash, scopeLevel, key);
				// 4) assure an assignment
				inFile >> input;
				if (input == "=")
				{
					// 5) get data
					inFile >> data;
					// 6) insert data
					getHash.InsertData(data, holdHash, key);
				}
			}
			else if (command == "PRINT")
				// Stream print, call print function
			{
				// 1) get input
				inFile >> input;
				key = input;
				// 2) print variable name
				cout << input;
				// 3) hash variable
				holdHash = getHash.Hash(input);
				// 4) call print function which will determine if variable is defined
				getHash.Print(holdHash, scopeLevel, key);
			}
			else if (command == "MAX")
				// will call max function. Takes commands in the format "MAX FIRSTVARIABLE SECONDVARIABLE"
			{
				// 1) get first variable
				inFile >> input;
				key = input;
				// 2) use data variable to hold first variable's hash
				data = getHash.Hash(input);
				// 3) get second variable
				inFile >> input;
				// 4) hold second variable's hash through regular holdHash
				holdHash = getHash.Hash(input);
				// 5) insert
				holdMax = getHash.Max(data, key, holdHash, input);
				// 6) holdMax will hold the returned max, but maximum is printed from max.
			}
			else if (command == "++")
				// checks for increment and calls increment 
			{
				getHash.Increment(holdHash, key);
			}
			else if (command == "--")
				// checks for decrement and calls decrement
			{
				getHash.Decrement(holdHash, key);
			}
			else if (command == "/")
				// check for divide, get data to divide by
			{
				inFile >> data;
				getHash.Divide(holdHash, data, key);
			}
			// check for multiply, get data to multiply by
			else if (command == "*")
			{
				inFile >> data;
				getHash.Multiply(holdHash, data, key);
			}
			else if (command == "%")
				// check for modulo, get data to mod by
			{
				inFile >> data;
				getHash.Modulus(holdHash, data, key);
			}
			else if (command == "^")
				//check for exponent, get the power
			{
				inFile >> data;
				getHash.Exponent(holdHash, data, key);
			}
			else if (command == "+")
				// check for addition, get data to add to
			{
				inFile >> data;
				getHash.Addition(holdHash, data, key);
			}
			else if (command == "-")
				// check for subtraction, get data to subtract by
			{
				inFile >> data;
				getHash.Subtraction(holdHash, data, key);
			}
			else if (command == "=")
				// check for a data declaration
			{
				inFile >> data;
				getHash.InsertData(data, holdHash, key);
			}
			else
				/*assume the possibility of a starting variable, get the hash.
				If the subject is not a variable the hash value will end up
				being ignored/ passed over.*/
			{
				key = command;
				holdHash = getHash.Hash(command);
			}
		}
	}
	void beginHashing(string filename)
		// initializes the table and calls the command function with the filename
	{
		getHash.initializeArray();
		Command(filename);
	}
};
int main()
{
	BORG callBorg;
	/* instance of borg allows use of borg functions. The construction allows
	for a simple function call with the name of the file inserted.*/
	callBorg.beginHashing("BORG.txt");
	// printed blank line allows delineation between outputs of each file compile
	cout << endl;
	callBorg.beginHashing("TEST.txt");
}
/*
SAMPLE OUTPUT:

BORAMIR IS 25
LEGOLAS IS 101
GANDALF IS UNDEFINED
BORAMIR IS 26
GANDALF IS 49
BORAMIR IS 52
GANDALF IS UNDEFINED
LEGOLAS IS 1000
LEGOLAS IS 1000
LEGOLAS IS 999

TEST ADDITIONAL OUTPUT:

KRISTA IS 100
ANDY IS 150
MAX IS 150
KRISTA IS 102
ANDY IS 173
KRISTA IS 2
ANDY IS 164
KRISTA IS 16
KRISTA IS 8

*/
