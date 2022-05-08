//#pragma once

#include "Graph.h"
class MinHeap
{
    class Pair {
         friend class MinHeap;
        Vertex* key;
        int value;
        Pair() : key(NULL), value(INF) {};
        Pair(Vertex* key, int value): key(key), value(value){};
        void decreaseKey(int newValue){value=newValue;};
    };   
 
private :
    Pair* map;
    int size = 0;
public:
    friend class Pair;
	MinHeap(Vertex* vers,int size);
    ~MinHeap(){delete[] map;};
    Vertex* deleteMin();
    Vertex* getMin();
    bool isEmpty();
    void decreaseKey(Vertex* v,int newKey);
    void fixHeap(int ind);
    int rightChild(int ind);
    int leftChild(int ind);
    int parent(int ind);
    int getMinChild(int ind);
};

