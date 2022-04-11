//#include "MinHeap.h"
//
//MinHeap::~MinHeap()
//{
//	if (isAllocated()) {
//		for (int i = 0; i < logicSize; i++) {
//
//
//			for (int j = 0; j < logicSize; j++)
//			{
//				delete[]data[i][j].other;
//
//			}
//			delete[]data[i];
//		}
//	}
//	delete[]data;
//}
//
//
//Pair** MinHeap::getData() const {
//	return data;
//}
//void MinHeap::setLogicSize(int size) {
//	logicSize = size;
//}
//
//
//bool MinHeap::isAllocated() const {
//	return Alocated;
//}
//
//int MinHeap::getLogicSize() const {
//	return logicSize;
//}
//
//Pair* MinHeap::min() {
//	if (logicSize < 1) {
//		cout << "wrong input" << endl;
//		exit(0);
//		return nullptr;
//	}
//	return (data)[0];
//}
//
//int MinHeap::LeftChild(int curr_inedx) const {
//	return (2 * curr_inedx + 1);
//}
//int MinHeap::RightChild(int curr_inedx)const {
//	return (2 * curr_inedx + 1);
//}
//int MinHeap::Parent(int curr_index)const {
//	return (curr_index - 1) / 2;
//}
//
//
//
//void MinHeap::insert(Pair* newP) {
//	
//	int i = logicSize;
//	data[i] = newP;
//	data[i]->myIndx = i;
//	logicSize++;
//
//	while ((i > 0) && ((data)[Parent(i)]->priority > (data)[(i)]->priority))
//	{
//		swap((data)[Parent(i)], (data)[(i)]);
//		data[i]->myIndx = i;
//		data[Parent(i)]->myIndx = Parent(i);
//		i = Parent(i);
//
//	}
//	
//}
//
//
//Pair* MinHeap::deleteMin() {
//	if (logicSize < 1) {
//		cout << "wrong input";
//		exit(0);
//		return nullptr;
//	}
//	
//	Pair* res = new Pair;
//		res= (data)[0];
//		logicSize--;
//		
//		if (logicSize > 0) {
//			data[0] = data[logicSize];
//			data[0]->myIndx = 0;
//		}
//			
//		
//		fixHeap(0);
//		return res;
//	
//}
//
//void MinHeap::creatEmpty() {
//	logicSize = 0;
//	data = new Pair*[MAXSIZE];
//	for (int i = 0; i < MAXSIZE; i++) {
//		data[i] = new Pair;
//		data[i]->other = new Pair;
//	}
//
//	Alocated = true;
//
//}
//void MinHeap::fixHeap(int curr_index) {
//	if (curr_index >= logicSize)
//		return;
//	int min;
//	int left = LeftChild(curr_index);
//	int right = RightChild(curr_index);
//
//	if ((left < logicSize) && (data[left]->priority < data[curr_index]->priority))
//		min = left;
//	else
//		min = curr_index;
//	if ((right < logicSize) && (data[right]->priority < data[curr_index]->priority))
//		min = right;
//
//	if (min != curr_index) {
//		swap(data[curr_index], data[min]);
//		data[curr_index]->myIndx = curr_index;
//		data[min]->myIndx = min;
//		fixHeap(min);
//	}
//}
//
//void MinHeap::deleteI(int indxToDelete) {
//
//	logicSize--;
//	if (logicSize > 1) {
//		data[indxToDelete] = data[logicSize];
//		fixHeap(indxToDelete);
//
//	}
//}
//#include "MinHeap.h"
