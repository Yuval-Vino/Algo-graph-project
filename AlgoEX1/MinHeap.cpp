#include "MinHeap.h"

MinHeap::MinHeap(Vertex* ver, int size) {
    this->size = size;
    map = new Pair[size];

    for (int i = 1; i < size; i++) {
        map[i] = Pair(&ver[i], INF);
        ver[i].minHeapIndex = i;
    }

    map[1].decreaseKey(0);
};

Vertex* MinHeap::deleteMin() {
    Vertex *res = map[1].key;
    swap(map[1], map[size-1]);
    size--;

    map[1].key->minHeapIndex = 1;
     map[size].key->minHeapIndex = size;
    fixHeap(1);
    return res;
}

void MinHeap:: fixHeap(int ind){
    int minChild = getMinChild(ind);
    if(minChild!=-1)
        if (map[ind].value > map[minChild].value) {
           swap(map[ind], map[minChild]);
            map[ind].key->minHeapIndex = ind;
            map[minChild].key->minHeapIndex = minChild;
            fixHeap(minChild);
        }       
};

Vertex* MinHeap::getMin() {
return map[1].key;
}

bool MinHeap::isEmpty() {
    return size == 1;
}

void MinHeap:: decreaseKey(Vertex* v,int newValue){
    map[v->minHeapIndex].decreaseKey(newValue);
   int curr=v->minHeapIndex;
    while(curr>1&& map[curr].value<map[parent(curr)].value)
    {
        swap(map[curr], map[parent(curr)]);
        map[curr].key->minHeapIndex = curr;
        map[parent(curr)].key->minHeapIndex = parent(curr);
        curr=parent(curr);
    }
}


//return right child
int  MinHeap::rightChild(int ind){
    return  2 * ind +1;
};
//return left child
int  MinHeap::leftChild(int ind){
    return 2 * ind ;
};
int  MinHeap::parent(int ind) {
    return ind  / 2;
};


int  MinHeap::getMinChild(int ind){
    if (rightChild(ind) < size) {
        if (map[leftChild(ind)].value < map[rightChild(ind)].value)
            return(leftChild(ind));
        return rightChild(ind);
    }
    if (leftChild(ind) < size)
        return leftChild(ind);

    return -1;//invalid no sons

};

