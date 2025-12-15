#include "graph.h"
#include <iostream>
using namespace std;

void CreateGraph(Graph &G) {
    G.First = nullptr; 
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = 0; 
    newNode->firstEdge = nullptr; 
    newNode->Next = G.First;
    G.First = newNode;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge newEdge = new ElmEdge;
    newEdge->Node = N2;
    newEdge->Next = N1->firstEdge;
    N1->firstEdge = newEdge; 

    newEdge = new ElmEdge;
    newEdge->Node = N1;
    newEdge->Next = N2->firstEdge;
    N2->firstEdge = newEdge;
}

void PrintInfoGraph(Graph G) {
    adrNode temp = G.First;
    while (temp != nullptr) {
        cout << "Node " << temp->info << ": ";
        adrEdge edge = temp->firstEdge;
        while (edge != nullptr) {
            cout << edge->Node->info << " ";
            edge = edge->Next;
        }
        cout << endl;
        temp = temp->Next;
    }
}
