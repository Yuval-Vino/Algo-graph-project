#pragma once
#include "Utils.h"
#include "Edge.h"
class Edge;
class Vertex
{
public:
    Vertex(int i) : index(i) {};
    Vertex();
    void addEdge(Vertex* u, int w);
    void removeEdge(Vertex* u);
    bool isAdjacent(Vertex* u);
    Vertex* getAdjList();
    Edge * getEdges();
    int getIndex();
    Edge* getHead();
    ~Vertex();
    int countAdjs();

    int minHeapIndex;
private: 
    int index;
    Edge* head = nullptr;
};