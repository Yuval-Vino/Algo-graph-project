// AlgoEX1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "UnionFind.h"
int kruskal(Graph g);
Edge* creatList(Graph g);
int compareEdge(const void* e1,const void* e2);
int main(int* argc , char** argv )
{
	
	string path /*= string(argv[1])*/;
	cout<<("Enter valid path");
	cin >> path;
	Graph g(path);
	Vertex* temp = g.getAdjList(2);
	int arr[] = { 10, 20, 30, 40 };
    UnionFind x(g);
	cout <<"Hello";
	int minWeight = kruskal(g);

	
}
 
int kruskal(Graph g) {
	Edge* edge_list = creatList(g) ;
	for(int i=0;i<g.getEdgeNumber();i++)
	{
		cout<<" Edge : "<< edge_list[i].getWieght();
	}
	return 1;
}

Edge* creatList(Graph g) {
	Edge* list = new Edge[g.getEdgeNumber()];
	int count=0;
	for (int i = 0; i < g.getVertexNumber(); i++)
	{
		const Edge* curr = g.getArray()[i].getEdges();
		while (curr)
		{
			list[count] = *curr;
			count++;
			curr=curr->next;
		}
	}
		for(int i=0;i<g.getEdgeNumber();i++)
	{
		cout<<" Edge : "<< list[i].getWieght();
	}
	cout<<endl;
	qsort(list, g.getEdgeNumber(), sizeof(Edge),compareEdge);
	return list;
} 
int compareEdge(const void* e1,const void* e2) {
	 
	return (*(int*)e2 - *(int*)e1 );
}