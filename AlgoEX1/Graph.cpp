
#include "Graph.h"

void Graph::removeEdge()
{
    
    istringstream tok(edgeToDelete);
    string subs;

    int res[2]; //index 0= vIndex 1=uIndex 2=Weight
    for (int i = 0; i < 2; i++) {

        tok >> subs;
        if (!isNumber(subs)) 
            myExit();

        res[i] = stoi(subs);
    }
    edgeNumber -= 2;

    
    Array[res[0]].removeEdge(&Array[res[1]]);
    Array[res[1]].removeEdge(&Array[res[0]]);
}

void  Graph::addEdge(int v, int u, int w)
{
    Array[v].addEdge(&Array[u], w);
}


bool Graph::isAdjacent(int v, int u)
{
    return Array[v].isAdjacent(&Array[u]);
}
Vertex* Graph::getAdjList(int v) {
    return Array[v].getAdjList();
}

Graph::Graph(string str)
{
    ifstream newfile;
     newfile.open(str,ios::in);  // open a file to perform write operation using file object
     if (!newfile.is_open())//checking whether the file is open
         myExit();//checking whether the file is open
      
      string currLine;//1 2 32  32=W,1,2=u,v
      getline(newfile, currLine);
      vertexNumber =stoi(currLine);
      getline(newfile, currLine);
      edgeNumber=stoi(currLine)*2;
      Array = new Vertex[vertexNumber+1];
      for (int i = 0; i <= vertexNumber; i++) 
          Array[i] = Vertex(i);
      
      for(int i=0;i<edgeNumber/2;i++)
      {
          (getline(newfile, currLine)); //read data from file object and put it into string
          addEdgeFromString(currLine);
      } 
     getline(newfile, edgeToDelete);
      newfile.close(); 
      isLinked();
   }

void Graph::addEdgeFromString(string line)
{
    istringstream tok(line);
    string subs;

    int res[3]; //index 0= vIndex 1=uIndex 2=Weight
    for (int i = 0; i < 3; i++) {

        tok >> subs;
        if (!isNumber(subs)) 
            myExit();
        res[i] = stoi(subs);
    }

    if (res[0] == res[1] || res[0] > vertexNumber || res[1] > vertexNumber || res[0] < 0 || res[1] < 0) 
        myExit();
     addEdge(res[0],res[1],res[2]);
     addEdge(res[1], res[0], res[2]);
}

int Graph::getVertexNumber() const {
    return vertexNumber;
}

Vertex* Graph::getArray() const {
    return Array;
}
int Graph::getEdgeNumber(){
    return edgeNumber;
}
Graph::~Graph() {

    delete[] Array;
}

void Graph::isLinked(){

	int size = getVertexNumber() + 1;
	int* color = new int[size]; 
	for (int i = 0; i < size; i++) 
		color[i] = WHITE;
	
	visit(&(getArray()[1]), color);
        
	for (int i = 1; i < size; i++)
        if (color[i] != BLACK)
            myExit();
}

void Graph::visit(Vertex* u,int * color) {
	color[u->getIndex()] = GRAY;
	Vertex * v;
	for (int i = 0; i < u->countAdjs(); i++) {
		v =&( u->getAdjList()[i]);
		if (color[v->getIndex()] == WHITE)
			visit(v, color);	
	}
	color[u->getIndex()] = BLACK;
}
