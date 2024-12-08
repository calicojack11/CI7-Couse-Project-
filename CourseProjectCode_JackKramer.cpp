#include <iostream>

using namespace std;

struct Node
{
	string city;
	int val;
};

struct Edge
{
	int start,
		dest,
		weight;
};

void createNodeList(Node[], int);
void welcomeMessage();
void createGraph(Edge[], int);
int menu();

int main()
{
	int menuChoice;
	Node cities[4];
	Edge drive[12] =
	{
		{ 0, 1, 16 }, { 0, 2, 24 }, { 0, 3, 33 },
		{ 1, 0, 16 }, { 1, 2, 18 }, { 1, 3, 26 },
		{ 2, 0, 24 }, { 2, 1, 18 }, { 2, 3, 30 },
		{ 3, 0, 33 }, { 3, 1, 26 }, { 3, 2, 30 }
	};

	welcomeMessage();
	
	createNodeList(cities, 4);

	cout << endl;

	cout << "Below is a graph of how much it would cost to go between two cities based on the numbering above. " << endl << endl;
		
	createGraph(drive, 12);

	cout << endl;

	menuChoice = menu();

	cout << endl;

	if (menuChoice == 1)
	{
		cout << "The shortest, cheapest trips are: " << endl;
		cout << "Riverside to Perris to Hemet to Moreno Valley to Riverside" << endl;
		cout << "The cost would be " << drive[1].weight + drive[8].weight + drive[10].weight + drive[3].weight << endl;
		cout << "Riverside to Moreno Valley to Hemet to Perris to Riverside" << endl;
		cout << "The cost would be " << drive[0].weight + drive[5].weight + drive[11].weight + drive[6].weight << endl;
	}
	if (menuChoice == 2)
	{
		cout << "The next cheapest trips are " << endl;
		cout << "Riverside to Moreno Valley to Perris to Hemet to Riverside" << endl;
		cout << "The cost would be " << drive[0].weight + drive[4].weight + drive[8].weight + drive[9].weight << endl;
		cout << "Riverside to Hemet to Perris to Moreno Valley to Riverside" << endl;
		cout << "The cost would be " << drive[2].weight + drive[11].weight + drive[7].weight + drive[3].weight << endl;
	}

	if (menuChoice == 3)
	{
		cout << "The most expensive trips are: " << endl;
		cout << "Riverside to Perris to Moreno Valley to Hemet to Riverside" << endl;
		cout << "The cost would be " << drive[1].weight + drive[7].weight + drive[5].weight + drive[9].weight << endl;
		cout << "Riverside to Hemet to Moreno Valley to Perris to Riverside" << endl;
		cout << "The cost would be " << drive[2].weight + drive[10].weight + drive[4].weight + drive[6].weight << endl;
	}
	
	return 0;
}

void createNodeList(Node nodeList[], int num)
{
	nodeList[num];
	nodeList[0].city = "Riverside";
	nodeList[1].city = "Moreno Valley";
	nodeList[2].city = "Perris";
	nodeList[3].city = "Hemet";

	for (int i = 0; i < num; i++)
	{
		nodeList[i].val = i;
		cout << nodeList[i].city << " = " << i << endl;
	}	
}

void welcomeMessage()
{
	cout << "Welcome to Solar Sales!" << endl;	
	cout << "The cities you are covering are Riverside, Moreno Valley, Perris, and Hemet." << endl;
	cout << "This is here to help you in planning your trip in saling our amazing solar panels in the quickest, cheapest way possible." << endl;
}

void createGraph(Edge edges[], int num)
{
	
	for (int i = 0; i < 3; i++)
	{
		cout << "( " << edges[i].start << ", " << edges[i].dest << ", " << edges[i].weight << ") ";
	}
	cout << endl;
	
	for (int i = 3; i < 6; i++)
	{
		cout << "( " << edges[i].start << ", " << edges[i].dest << ", " << edges[i].weight << ") ";
	}
	cout << endl;
	
	for (int i = 6; i < 9; i++)
	{
		cout << "( " << edges[i].start << ", " << edges[i].dest << ", " << edges[i].weight << ") ";
	}
	cout << endl;
	
	for (int i = 9; i < 12; i++)
	{
		cout << "( " << edges[i].start << ", " << edges[i].dest << ", " << edges[i].weight << ") ";
	}
	cout << endl;
}

int menu()
{
	int num;
	cout << "Cost of routes with those living in Riverside, inlcudes return trip home: " << endl;
	cout << "1. Shortest, cheapest paths" << endl;
	cout << "2. Next cheapest paths" << endl;
	cout << "3. Most expensive paths" << endl;
	cin >> num;
	return num;
}