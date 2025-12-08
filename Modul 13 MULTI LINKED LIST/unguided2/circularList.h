#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <string>
using namespace std;

typedef struct ElmList *address;
typedef struct List {
    address first;
} List;

typedef struct ElmList {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
    address next;
    address prev;
} ElmList;

void CreateList(List &L);
address alokasi(string nama, string nim, char jenis_kelamin, float ipk);
void dealokasi(address P);
void insertFirst(List &L, address P);
void insertAfter(List &L, address P, address Prec);
void insertLast(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address &P, address Prec);
void deleteLast(List &L, address &P);
address findElm(List L, string nim);
void printInfo(List L);

#endif
