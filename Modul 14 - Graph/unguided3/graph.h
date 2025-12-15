#ifndef GRAPH_H_INCLUDE
#define GRAPH_H_INCLUDE

typedef char infoGraph; 
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge; 
    adrNode Next; 
};

struct ElmEdge {
    adrNode Node; 
    adrEdge Next;  
};

struct Graph {
    adrNode First;  
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);  
void ConnectNode(adrNode N1, adrNode N2); 
void PrintInfoGraph(Graph G);  
void PrintDFS(Graph G, adrNode start);  
void PrintBFS(Graph G, adrNode start);  

#endif
