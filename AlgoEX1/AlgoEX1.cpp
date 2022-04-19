// AlgoEX1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "UnionFind.h"
int kruskal(Graph g);
Edge* creatList(Graph g);
int compareEdge(const void* e1,const void* e2);


int main(int* argc , char** argv )
{
	
	string path = string(argv[1]);
	cout<<("Enter valid path");
	//cin >> path;
	Graph g(path);
	Vertex* temp = g.getAdjList(2);
	int arr[] = { 10, 20, 30, 40 };
 
	int minWeight = kruskal(g);	
}
 
int kruskal(Graph g) {
	int sum = 0, cn = 0;
	Edge* L = creatList(g) ;
	Edge* F = new Edge[g.getVertexNumber()];

	Vertex* u_rep, *v_rep;

	UnionFind UF(g);
	for (int i = 0; i < g.getEdgeNumber(); i++) {
		u_rep = UF.find(L[i].getSrc());
		v_rep = UF.find(L[i].getDst());

		if(u_rep != v_rep){
			sum += L[i].getWieght();
			F[cn] = L[i];
			cn++;
			UF.Union(u_rep, v_rep);
		}
	}
	//TODO delete check
	for (int i = 0; i < g.getVertexNumber()-1; i++)
	{
		cout << "\n" << i << " Edge from " << F[i].src->index << " to " << F[i].dst->index << " Weight : " << F[i].getWieght() << endl;
	}
	cout << "The total weight of the tree : " << sum;
	return sum;
}

Edge* creatList(Graph g) {	
	Edge* list = new Edge[g.getEdgeNumber()];
	int count=0;
	for (int i = 0; i <= g.getVertexNumber(); i++)
	{
		const Edge* curr = g.getArray()[i].getEdges();
		while (curr)
		{
			list[count] = *curr;
			count++;
			curr = curr->next;
		}
	}

	cout<<endl;
	qsort(list, g.getEdgeNumber(), sizeof(Edge),compareEdge);

	//TODO delete chack
	//for (int i = 0; i < g.getEdgeNumber(); i++)
	//{
	//	cout << "\n" << i << " Edge from " << list[i].src->index << " to " << list[i].dst->index << " Weight : " << list[i].getWieght() << endl;
	//}
	return list;
} 

int compareEdge(const void* e1,const void* e2) { 
	return ( ((Edge*)e1)->getWieght() - ((Edge*)e2)->getWieght());
}
//
void DFS(Graph G) {
	//int** Color = new int
}