#pragma once
#include "Utils.h"
class Vertex
{
public:
    class Edge
    {
        
        friend class Vertex;
        Vertex* dst=nullptr;
        int w;
        Edge* next=nullptr,*prev=nullptr;
        Edge(int w, Vertex* u) :dst(u) , w(w){};
        Edge();
        ~Edge() {};

    };

    
    friend  class Edge;
    int index;
    Edge* head= nullptr;
    Vertex(int i) : index(i) {};
    Vertex();
    void addEdge(Vertex* u, int w);
    void removeEdge(Vertex* u);
    bool isAdjacent(Vertex* u);
    Vertex* getAdjList();
    ~Vertex();
private:
    int countAdjs();
};