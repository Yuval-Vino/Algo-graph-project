#include "UnionFind.h"

UnionFind::UnionFind(const Graph &g) {
	size = g.getVertexNumber()+1;
	mapArray = new MyMap[size];
	for (int i = 0; i < size; i++)
		makeSet(&(g.getArray()[i]));

};

void UnionFind::makeSet(Vertex* v)
{   
	mapArray[v->getIndex()] = MyMap(v);
}

Vertex*   UnionFind::find( Vertex* v) {
	
    Vertex* parent = mapArray[v->getIndex()].getParent();
   
	
	 if(v == parent)
	   return parent;

     Vertex* res = find(parent);
	 mapArray[v->getIndex()].setParent(&mapArray[res->getIndex()]);
     return res;
}

void UnionFind::Union(Vertex* rep_v, Vertex* rep_u) {
	
	if(mapArray[rep_v->getIndex()].getSize() > mapArray[rep_u->getIndex()].getSize())
		mapArray[rep_u->getIndex()].setParent(&mapArray[rep_v->getIndex()]);
	else
		mapArray[rep_v->getIndex()].setParent(&mapArray[rep_u->getIndex()]);

}