#include "Graph.h"

void Graph::removeEdge()
{
    while (edgeToDelete[edgeToDelete.length() - 1] == ' ')
        edgeToDelete.pop_back();

    istringstream tok(edgeToDelete);
    string subs;
    int countNumber = 0;
    int res[2]; //index 0= vIndex 1=uIndex 

    while (!tok.eof())
    {
        tok >> subs;
        if (!isNumber(subs))
            myExit();
        res[countNumber] = stoi(subs);
        countNumber++;

    }

    if (res[0] < 1 || res[0] > vertexNumber || res[1] < 1 || res[1] > vertexNumber || !isAdjacent(res[0], res[1]) || countNumber != 2) //check if edge to remove is legal
        myExit();
 
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
     newfile.open(str,ios::in);  
     if (!newfile.is_open())
         myExit();
      
      string currLine;
      getline(newfile, currLine);
      vertexNumber =stoi(currLine);
      getline(newfile, currLine);
      edgeNumber=stoi(currLine)*2;
      Array = new Vertex[vertexNumber+1];
      for (int i = 0; i <= vertexNumber; i++) 
          Array[i] = Vertex(i);
      
      for(int i=0;i<edgeNumber/2;i++)
      {
          (getline(newfile, currLine)); 
          addEdgeFromString(currLine);
      } 
    
     getline(newfile, edgeToDelete);
     string s;
     getline(newfile, s);
     if (s.length() > 0 || !newfile.eof())
         myExit();
      newfile.close(); 
      isLinked();
}

void Graph::addEdgeFromString(string line)
{
    while (line[line.length()-1]==' ')
        line.pop_back();

    istringstream tok(line);
    string subs;
    int countNumber = 0;
    int res[3]; //index 0= vIndex 1=uIndex 2=Weight

    while (!tok.eof())
    {
        tok >> subs;
        if (!isNumber(subs))
            myExit();
        res[countNumber] = stoi(subs);
        countNumber++;

    }

    if (countNumber != 3)
        myExit();

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
        if (color[i] != BLACK) {
            cout << "No MST" << endl;
            exit(1);
        }
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
