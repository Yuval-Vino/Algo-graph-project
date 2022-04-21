#pragma once
#include "Vertex.h"

class Graph
{
public:

  Graph() : vertexNumber(1) {};
  Graph(string str);//from file
  void makeEmptyGraph(int size);
  void addEdge(int v,int u,int w);
  bool isAdjacent(int v, int u);
  Vertex* getAdjList(int v);
  void removeEdge(int v,int u);
  int getVertexNumber() const;
  Vertex* getArray() const;
  int getEdgeNumber();
  void isLinked();
  void visit(Vertex* u,int * color);
  ~Graph();
private:
    string edgeToDelete;
    void addEdgeFromString(string line);
    int edgeNumber;
    int vertexNumber;
    Vertex* Array = nullptr;
    

};

