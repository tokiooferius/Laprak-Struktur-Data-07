#include "circularList.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.first = NULL;
}

address alokasi(string nama, string nim, char jenis_kelamin, float ipk) {
    address P = new ElmList;
    P->nama = nama;
    P->nim = nim;
    P->jenis_kelamin = jenis_kelamin;
    P->ipk = ipk;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        P->next = L.first;
        P->prev = L.first;
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        last->next = P;
        P->prev = last;
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfter(List &L, address P, address Prec) {
    P->next = Prec->next;
    Prec->next = P;
    P->prev = Prec;
    if (P->next != NULL) {
        P->next->prev = P;
    }
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        P->next = L.first;
        P->prev = L.first;
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        last->next = P;
        P->prev = last;
        P->next = L.first;
        L.first->prev = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first == NULL) {
        P = NULL;
    } else {
        P = L.first;
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        if (L.first == L.first->next) {
            L.first = NULL;
        } else {
            L.first = L.first->next;
            last->next = L.first;
            L.first->prev = last;
        }
    }
}

void deleteAfter(List &L, address &P, address Prec) {
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != NULL) {
        P->next->prev = Prec;
    }
    P->next = NULL;
    P->prev = NULL;
}

void deleteLast(List &L, address &P) {
    address last = L.first;
    if (L.first != NULL) {
        while (last->next != L.first) {
            last = last->next;
        }
        if (L.first == L.first->next) {
            L.first = NULL;
        } else {
            last->prev->next = L.first;
            L.first->prev = last->prev;
        }
    }
    P = last;
    delete P;
}

address findElm(List L, string nim) {
    address P = L.first;
    while (P != NULL && P->nim != nim) {
        P = P->next;
    }
    return P;
}

void printInfo(List L) {
    address P = L.first;
    if (P != NULL) {
        do {
            cout << "Nama : " << P->nama << endl;
            cout << "NIM  : " << P->nim << endl;
            cout << "L/P  : " << P->jenis_kelamin << endl;
            cout << "IPK  : " << P->ipk << endl;
            cout << endl;
            P = P->next;
        } while (P != L.first);
    } else {
        cout << "List Kosong!" << endl;
    }
}
