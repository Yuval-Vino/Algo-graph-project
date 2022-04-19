#pragma once
#include "Vertex.h"
class Vertex;
class Edge
{

    friend class Vertex;
    Vertex* dst = nullptr;
    int w;
    public:
    Edge* next = nullptr, * prev = nullptr;
    Edge(int w, Vertex* u) :dst(u), w(w) {};
    Edge(): w(0){};
    int getWieght() { return w;};
    operator int() const {return w;}
    
    ~Edge() {};

};
