#include "UnionFind.h"
UnionFind::UnionFind(const Graph &g) {
	size = g.getVertexNumber();
	mapArray = new MyMap[size];
	for (int i = 0; i < size; i++)
		makeSet(&(g.getArray()[i]));

};
void UnionFind::makeSet(Vertex* v)
{   

	mapArray[v->index] = MyMap(v);
}


Vertex*   UnionFind::find( Vertex* v) {
	
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