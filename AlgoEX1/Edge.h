#pragma once
#include "Vertex.h"
class Vertex;
class Edge
{
public:
    friend class Vertex;

    Edge* next = nullptr, * prev = nullptr;
    Edge(int w, Vertex* u, Vertex* v) :src(u),dst(v), w(w) {};
    Edge(): w(0){};
    int getWieght() { return w;};
    Vertex* getDst(){return dst;};
    Vertex* getSrc(){return src;};
    operator int() const {return w;}
    static int compare(const void* e1,const void* e2) { 	return ( ((Edge*)e1)->getWieght() - ((Edge*)e2)->getWieght());};

    ~Edge() {};
private:
    Vertex* dst = nullptr;
    Vertex* src = nullptr;
    int w;
};
