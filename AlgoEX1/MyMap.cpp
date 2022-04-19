#include "MyMap.h"
MyMap::MyMap() {
	size = 1;	
}void MyMap::setParent(MyMap* new_map) {	parent = new_map->parent;	new_map->addSize(this->getSize());}Vertex* MyMap::getParent() {	return parent;}
void MyMap::addSize(int new_size) {
	size += new_size;
}
int MyMap::getSize() {
	return size;
}