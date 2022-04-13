#include "MyMap.h"MyMap::MyMap(Vertex* new_v) {	size = 1;	v = new_v;	parent = new_v;}void MyMap::setParent(MyMap* new_map) {	parent = new_map->parent;	new_map->addSize(this->getSize());}Vertex* MyMap::getParent() {	return parent;}
void MyMap::addSize(int new_size) {
	size += new_size;
}
int MyMap::getSize() {
	return size;
}