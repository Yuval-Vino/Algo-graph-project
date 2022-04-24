#pragma once
#include "Graph.h"
class MyMap
{
public:
	
	MyMap();
	MyMap(Vertex* new_v):v(new_v), parent(new_v){};
    void setParent(MyMap* new_map);
	void addSize(int size);
	int getSize();
    Vertex *getParent();
private:
	Vertex* v = NULL;
	Vertex* parent = NULL;
	int size = 1;
};

