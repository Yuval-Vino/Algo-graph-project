#pragma once
#include "Vertex.h"
class MyMap
{
public:
	Vertex* v = nullptr;
	Vertex* parent = nullptr;
	int size=0;
	MyMap();
	MyMap(Vertex* new_v);
    void setParent(MyMap* new_map);
	void addSize(int size);
	int getSize();
    Vertex *getParent();
};

