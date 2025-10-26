#include <iostream>
#include <string>
using namespace std;

struct Kendaraan {
    string nopol, warna;
    int thnBuat;
    Kendaraan* next;
    Kendaraan* prev;
};

Kendaraan* first = nullptr;
Kendaraan* last = nullptr;

void insertLast(string nopol, string warna, int thn) {
    Kendaraan* newNode = new Kendaraan();
    newNode->nopol = nopol;
    newNode->warna = warna;
    newNode->thnBuat = thn;
    newNode->next = nullptr;
    newNode->prev = last;

    if (first == nullptr)
        first = newNode;
    else
        last->next = newNode;

    last = newNode;
}

void printInfo() {
    Kendaraan* temp = first;
    cout << "\nDaftar Kendaraan:\n";
    while (temp != nullptr) {
        cout << "Nopol: " << temp->nopol
             << " | Warna: " << temp->warna
             << " | Tahun: " << temp->thnBuat << endl;
        temp = temp->next;
    }
}

int main() {
    insertLast("D001", "Merah", 2010);
    insertLast("D002", "Hitam", 2012);
    insertLast("D003", "Putih", 2015);

    printInfo();
    return 0;
}