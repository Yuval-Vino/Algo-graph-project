#pragma once
#include "Vertex.h"

class Graph
{
public:
  Vertex* Array = nullptr;
 /*   Graph * My_kruskal,*my_prim;*/
    Graph() : vertexNumber(1) {};
    Graph(string str);//from file
    void makeEmptyGraph(int size);
    void addEdge(int v,int u,int w);
    bool isAdjacent(int v, int u);
    Vertex* getAdjList(int v);
    void removeEdge(int v,int u);
    int getVertexNumber() const;
    Vertex* getArray() const;
    int getEdgeNumber();
private:
    string edgeToDelete;
    void addEdgeFromString(string line);
    int edgeNumber;
     int vertexNumber;
    

};

