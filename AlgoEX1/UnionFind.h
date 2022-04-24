#pragma once
#include "MyMap.h"

class UnionFind
{
public:

   MyMap*  mapArray = nullptr;
   UnionFind(const Graph &g);
   void makeSet(Vertex* v);
   Vertex*  find(Vertex* v);
   void  Union(Vertex* v, Vertex* u);
private: 

	int size;
};

