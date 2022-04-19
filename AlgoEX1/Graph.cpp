
#include "Graph.h"

void Graph::removeEdge(int v,int u)
{
    Array[v].removeEdge(&Array[u]);
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
   if(!newfile.is_open())//checking whether the file is open
    exit(1) ;
  
      //checking whether the file is open
      string currLine;//1 2 32  32=W,1,2=u,v
      getline(newfile, currLine);
      vertexNumber =stoi(currLine);
      getline(newfile, currLine);
      edgeNumber=stoi(currLine);
      Array = new Vertex[vertexNumber];
      for (int i = 0; i < vertexNumber; i++) {
          Array[i] = Vertex(i);
      }
      for(int i=0;i<edgeNumber;i++)
      {
          (getline(newfile, currLine)); //read data from file object and put it into string
          addEdgeFromString(currLine);
 
  
      } 
     getline(newfile, edgeToDelete);
      newfile.close(); 
   }

void Graph::addEdgeFromString(string line)
{
    istringstream tok(line);
    string subs;
    int res[3]; //index 0= vIndex 1=uIndex 2=Weight
    for (int i = 0; i < 3; i++) {

        tok >> subs;
        if (!isNumber(subs))
            throw new runtime_error("Not a number!");
        res[i] = stoi(subs);
    }

    if(res[0]==res[1]||res[0]> vertexNumber ||res[1]> vertexNumber ||res[0]<0||res[1]<0)
        throw new runtime_error("Wrong index for edge");
     addEdge(res[0],res[1],res[2]);
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