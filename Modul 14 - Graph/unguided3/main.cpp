#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    adrNode A = G.First;
    adrNode B = A->Next;
    adrNode C = B->Next;
    adrNode D = C->Next;
    adrNode E = D->Next;
    adrNode F = E->Next;

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(C, E);
    ConnectNode(D, E);
    ConnectNode(E, F);
    ConnectNode(F, A); 

    cout << "DFS Traversal: ";
    PrintDFS(G, A);
    cout << endl;

    cout << "BFS Traversal: ";
    PrintBFS(G, A);
    cout << endl;

    return 0;
}
