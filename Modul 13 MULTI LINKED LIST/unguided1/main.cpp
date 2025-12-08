#include <iostream>
#include "circularList.h"
using namespace std;

int main() {
    List L;
    address P;
    
    CreateList(L);

    P = alokasi("Nanda B. P.", "11013134395", 'L', 3.3);
    insertFirst(L, P);
    
    P = alokasi("David H. M.", "11013130314", 'L', 3.71);
    insertLast(L, P);
    
    P = alokasi("Masiyah Nur Aulia", "1103130120", 'P', 4.0);
    insertFirst(L, P);
    
    printInfo(L);

    deleteFirst(L, P);
    cout << "Setelah Delete First:" << endl;
    printInfo(L);

    return 0;
}
