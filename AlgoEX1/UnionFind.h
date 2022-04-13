#pragma once
#include "Vertex.h"
#include "MyMap.h"
class UnionFind
{

  MyMap*  mapArray;
   int size;
   UnionFind(int size);
   void makeSet(Vertex* v);
   Vertex*  find(Vertex* v);
   void  Union(Vertex* v, Vertex* u);
};

