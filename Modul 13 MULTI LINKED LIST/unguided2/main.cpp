#include <iostream>
#include "circularList.h"
using namespace std;

int main() {
    List L;
    address P;

    CreateList(L);

    P = alokasi("Danu", "04", 'L', 4.0);
    insertFirst(L, P);  
    P = alokasi("Ali", "01", 'L', 3.3);
    insertLast(L, P);  
    P = alokasi("Cindi", "03", 'P', 3.5);
    insertAfter(L, P, L.first);  
    P = alokasi("Bobi", "02", 'L', 3.71);
    insertAfter(L, P, L.first); 
    P = alokasi("Eli", "05", 'P', 3.4);
    insertLast(L, P);  
    P = alokasi("Fahmi", "06", 'L', 3.45);
    insertLast(L, P);  
    P = alokasi("Gita", "07", 'P', 3.75);
    insertLast(L, P);  
    P = alokasi("Hilmi", "08", 'P', 3.3);
    insertLast(L, P);  

    cout << "coba insert first, last, dan after" << endl;
    printInfo(L);  

    return 0;
}
