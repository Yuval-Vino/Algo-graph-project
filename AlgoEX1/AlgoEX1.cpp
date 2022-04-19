// AlgoEX1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Graph.h"

int main()
{
	string path;
	cout<<("Enter valid path");
	cin >> path;
	Graph g(path);
	Vertex* temp = g.getAdjList(2);
	int arr[] = { 10, 20, 30, 40 };

	kruskal(g);

	
}
