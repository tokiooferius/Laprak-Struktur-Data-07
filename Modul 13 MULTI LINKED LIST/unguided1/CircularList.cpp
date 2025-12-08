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
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
  if (L.first == NULL) {
        L.first = P;
        P->next = L.first;
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        last->next = P;
        P->next = L.first;
        L.first = P;
    }
}

void insertAfter(List &L, address P, address Prec) {
    P->next = Prec->next;
    Prec->next = P;
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        P->next = L.first;
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        last->next = P;
        P->next = L.first;
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
        }
    }
}

void deleteAfter(List &L, address &P, address Prec) {
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}

void deleteLast(List &L, address &P) {
    address last = L.first;
    address beforeLast;
    if (L.first != NULL) {
        while (last->next != L.first) {
            beforeLast = last;
            last = last->next;
        }
        if (L.first == L.first->next) {
            L.first = NULL;
        } else {
            beforeLast->next = L.first;
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
            cout << "Nama: " << P->nama << ", NIM: " << P->nim << ", Jenis Kelamin: " 
            << P->jenis_kelamin << ", IPK: " << P->ipk << endl;
            P = P->next;
        } while (P != L.first);
    } else {
        cout << "List Kosong!" << endl;
    }
}
