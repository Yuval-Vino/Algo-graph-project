//#pragma once

#include "Graph.h"
class MinHeap
{
    class Pair {
         friend class MinHeap;
        Vertex* key;
        int value;
        Pair() : key(NULL), value(INFINITY) {};
        Pair(Vertex* key, int value): key(key), value(value){};
        void decreaseKey(int newValue){value=newValue;};
    };
    public:
    friend class Pair;
    int size=0;
private :
    Pair* map;
public:
	MinHeap(Vertex* vers,int size);
    ~MinHeap(){delete[] map;};
    Vertex* deleteMin();
    Vertex* getMin();
    bool isEmpty();
    void decreaseKey(Vertex* v,int newKey);
    int parentIndex(Vertex* v);
    void fixHeap(int ind);
    int rightChild(int ind);
    int leftChild(int ind);
    int nodeParent(int ind);
    int getMinChild(int ind);
};

