#pragma once
#include "MyMap.h"

class UnionFind
{
public:

   MyMap*  mapArray = nullptr;
   int size;
   UnionFind(const Graph &g);
   void makeSet(Vertex* v);
   Vertex*  find(Vertex* v);
   void  Union(Vertex* v, Vertex* u);
};

