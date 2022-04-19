//#pragma once
#include "Vertex.h"
#include "Graph.h"
class MinHeap
{
    Vertex** vArray;
    int size=0;
    
	MinHeap(Graph g);
    Vertex* deleteMin();
    void insert(Vertex* v);
    Vertex* getMin();
    bool isEmpty();
    void decreaseKey();
    int parentIndex(Vertex* v);
    void fixHeap();

};

