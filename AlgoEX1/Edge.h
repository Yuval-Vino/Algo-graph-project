#pragma once
#include "Vertex.h"
class Vertex;
class Edge
{
public:
    friend class Vertex;
    Vertex* dst = nullptr;
    Vertex* src = nullptr;
    int w;
    
    Edge* next = nullptr, * prev = nullptr;
    Edge(int w, Vertex* u, Vertex* v) :src(u),dst(v), w(w) {};
    Edge(): w(0){};
    int getWieght() { return w;};
    Vertex* getDst(){return dst;};
    Vertex* getSrc(){return src;};
    operator int() const {return w;}
    
    ~Edge() {};

};
