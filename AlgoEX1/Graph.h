#pragma once
#include "Vertex.h"

class Graph
{
public:
    int vertexNumber;
    Vertex* Array;
    Graph * My_kruskal,*my_prim;
    Graph() : vertexNumber(1) {};
    Graph(string str);//from file
    void makeEmptyGraph(int size);
    void addEdge(int v,int u,int w);
    bool isAdjacent(int v, int u);
    Vertex* getAdjList(int v);
    void removeEdge(int v,int u);
private:
    string edgeToDelete;
    void addEdgeFromString(string line);

};

