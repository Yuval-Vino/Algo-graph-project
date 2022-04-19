#include "UnionFind.h"
UnionFind::UnionFind(Graph g) {
	
	mapArray = new MyMap[new_size];
	 size = new_size;
};
void UnionFind::makeSet(Vertex* v)
{   
	mapArray[v->index] = MyMap(v);
}

//if x.parent ==x return x
//return  x=find(x.parent)

Vertex*   UnionFind::find(Vertex* v) {
	
    Vertex* parent = mapArray[v->index].parent;

	
	 if(v == parent)
	   return parent;

     Vertex* res = find(parent);
	 mapArray[v->index].setParent(&mapArray[res->index]);
     return res;
}

void UnionFind::Union(Vertex* v, Vertex* u) {
	Vertex* repV = find(v);
	Vertex* repU = find(u);
	if(mapArray[repV->index].getSize() > mapArray[repU->index].getSize())
		mapArray[repU->index].setParent(&mapArray[repV->index]);
	else
		mapArray[repV->index].setParent(&mapArray[repU->index]);

}