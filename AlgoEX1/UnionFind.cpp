#include "UnionFind.h"
UnionFind::UnionFind(const Graph &g) {
	size = g.getVertexNumber()+1;
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

void UnionFind::Union(Vertex* rep_v, Vertex* rep_u) {
	
	if(mapArray[rep_v->index].getSize() > mapArray[rep_u->index].getSize())
		mapArray[rep_u->index].setParent(&mapArray[rep_v->index]);
	else
		mapArray[rep_v->index].setParent(&mapArray[rep_u->index]);

}