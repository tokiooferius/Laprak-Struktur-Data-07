#include "graph.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void CreateGraph(Graph &G) {
    G.First = nullptr; // Inisialisasi graph kosong
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = 0; // Node belum dikunjungi
    newNode->firstEdge = nullptr; // Tidak ada edge
    newNode->Next = G.First;
    G.First = newNode; // Menambahkan node ke graph
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge newEdge = new ElmEdge;
    newEdge->Node = N2;
    newEdge->Next = N1->firstEdge;
    N1->firstEdge = newEdge; // Menambahkan edge dari N1 ke N2

    // Karena ini graph tidak berarah, tambahkan juga edge dari N2 ke N1
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

void DFS(adrNode node) {
    
    stack<adrNode> S;
    node->visited = 1; 
    S.push(node);

    while (!S.empty()) {
        adrNode current = S.top();
        S.pop();
        cout << current->info << " ";

        adrEdge edge = current->firstEdge;
        while (edge != nullptr) {
            if (edge->Node->visited == 0) {
                edge->Node->visited = 1; 
                S.push(edge->Node); 
            }
            edge = edge->Next;
        }
    }
}

void PrintDFS(Graph G, adrNode start) {

    adrNode temp = G.First;
    while (temp != nullptr) {
        temp->visited = 0;
        temp = temp->Next;
    }
   
    DFS(start);
}

void BFS(adrNode start) {
   
    queue<adrNode> Q;
    start->visited = 1; 
    Q.push(start); 

    while (!Q.empty()) {
        adrNode current = Q.front();
        Q.pop();
        cout << current->info << " "; 

        adrEdge edge = current->firstEdge;
        while (edge != nullptr) {
            if (edge->Node->visited == 0) {
                edge->Node->visited = 1;
                Q.push(edge->Node); 
            }
            edge = edge->Next;
        }
    }
}

void PrintBFS(Graph G, adrNode start) {

    adrNode temp = G.First;
    while (temp != nullptr) {
        temp->visited = 0;
        temp = temp->Next;
    }

    BFS(start);
}
