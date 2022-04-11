#include "Vertex.h"

void Vertex::addEdge(Vertex* v, int w) {

    Edge* newEdge= new Edge(w, v);
    newEdge->next=head;

    if (head != nullptr)
        head->prev = newEdge;

    head=newEdge;
    
}

void Vertex::removeEdge(Vertex* V){
     
    Edge* currNeigbor = this->head;
   
    while (currNeigbor != nullptr && currNeigbor->dst != V) 
        currNeigbor = currNeigbor->next;
    
    if (currNeigbor->dst == V)
    {
        if (currNeigbor->prev)
            currNeigbor->prev->next = currNeigbor->next;
        else
            head = currNeigbor->next;

        if (currNeigbor->next)   
            currNeigbor->next->prev = currNeigbor->prev; 
                            
         delete currNeigbor;
    }
}


Vertex::~Vertex(){
     
    Edge* curr = this->head,*tmp;
   
    while (curr)
    {
        tmp=curr->next;
        delete curr;
        curr=tmp;
    }
}
bool Vertex::isAdjacent(Vertex* u)
{
        Edge* curr=this->head;
        while(curr){
            if (curr->dst == u)
                return true;
            curr = curr->next;
        }
        return false;
}
Vertex* Vertex::getAdjList() {
    Vertex* res = new Vertex[countAdjs()];
    Edge* curr = head;
    int cn = 0;
    while (curr) 
    {
        res[cn] = *(curr->dst);
        cn++;
        curr = curr->next;
    }

    return res;
}


int Vertex::countAdjs() {
    int cn = 0;
    Edge* curr = head;
    while (curr)
    {
        cn++;
        curr = curr->next;
    }
    return cn;
}
Vertex::Vertex(){
    index=-1;
    head=nullptr;
}

    