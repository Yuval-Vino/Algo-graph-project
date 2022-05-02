// AlgoEX1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "UnionFind.h"
#include "MinHeap.h"
int kruskal(Graph *g);
Edge* creatList(Graph *g);
int prim(Graph* g);
void print_output(int kruskal_1res,int kruskal_2res,int prim_res,string outputpath);
int main(int* argc , char** argv )
{
	
	string path = string(argv[1]);
	string outpath = string(argv[2]);
	Graph g(path);
	g.isLinked();
	int kruskal_1res = kruskal(&g);
	int prim_res = prim(&g);
	g.removeEdge();
	g.isLinked();
	int kruskal_2res = kruskal(&g);
	print_output( kruskal_1res, kruskal_2res, prim_res, outpath);


}
int prim(Graph* g) {  
	int n = g->getVertexNumber() + 1;
	bool* InT = new bool[n];
	int res =0;
	
	int* min = new int[n];
	MinHeap Q = MinHeap(g->getArray(), g->getVertexNumber() + 1);
	for (int i = 1; i < n; i++) {
		InT[i] = false;
		min[i] = INF;
	}
	InT[1] = true;
	min[1] = 0;
	 

	while (!Q.isEmpty()) {
		Vertex* u = Q.deleteMin();
		InT[u->getIndex()] = true;
		Edge* Adj = u->getHead();
	
		while (Adj) {
			int vIndx = Adj->getDst()->getIndex();
			if (!InT[vIndx] && Adj->getWieght() < min[vIndx]) {//test change and to or if in tree but his wheight can be smaller
				int w = Adj->getWieght();
				min[vIndx] = Adj->getWieght();
				Q.decreaseKey(Adj->getDst(), Adj->getWieght());	
			}
			Adj = Adj->next;
		}
	}
	
	for (int i = 1; i < n; i++) 
		res += min[i];


	return res;
}


void print_output(int kruskal_1res,int kruskal_2res,int prim_res,string outputpath){
		cout << "Kruskal < " << kruskal_1res <<">"<<endl;
		cout << "Prim <" << prim_res << ">" << endl;
		cout << "Kruskal <" << kruskal_2res << ">" << endl;
		
		ofstream out_file;
		out_file.open(outputpath);
		out_file << "Kruskal " << kruskal_1res << endl;
		out_file << "Prim " << kruskal_1res << endl;
		out_file << "Kruskal2 " << kruskal_2res << endl;
}





 
int kruskal(Graph *g) {
	int sum = 0, cn = 0;
	Edge* L = creatList(g) ;
	Edge* F = new Edge[g->getVertexNumber()];

	Vertex* u_rep, *v_rep;

	UnionFind UF(*g);
	for (int i = 0; i < g->getEdgeNumber(); i++) {
		u_rep = UF.find(L[i].getSrc());
		v_rep = UF.find(L[i].getDst());

		if(u_rep != v_rep){
			sum += L[i].getWieght();
			F[cn] = L[i];
			cn++;
			UF.Union(u_rep, v_rep);
		}
	}

	return sum;
}

Edge* creatList(Graph* g) {	
	Edge* list = new Edge[g->getEdgeNumber()];
	int count=0;
	for (int i = 0; i <= g->getVertexNumber(); i++)
	{
		const Edge* curr = g->getArray()[i].getEdges();
		while (curr)
		{
			list[count] = *curr;
			count++;
			curr = curr->next;
		}
	}


	qsort(list, g->getEdgeNumber(), sizeof(Edge),Edge::compare);

	return list;
} 


