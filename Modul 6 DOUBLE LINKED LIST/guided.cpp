#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void insertDepan(int data) {
    Node* newNode = new Node();
    newNode-> data;
    newNode-> prev = nullptr;
    newNode-> next = head;
    
    if(head != nullptr)
        head-> prev = newNode;
    else 
    tail = newNode;
    
    head = newNode;
    cout << "Data " << data << "berhasil ditambahkan didepan.\n";
}

void insertBelakangan(int data) {
    Node* newNode = new Node();
    newNode-> data = data;
    newNode-> next = nullptr;
    newNode-> prev =  tail;

    if (tail != nullptr)
        tail-> next = newNode;
    else
        head = newNode;
    tail = newNode;
    cout << "Data " << data << "berhasil ditambahkan dibelakang.\n";
}

void insertSetelah(int target, int data) {
    Node* current = head;
    while (current != nullptr && current-> data != target)
        current = current-> next;
    if (current == nullptr) {
        cout << "Data " << target << "tidak ditemukan.\n"
        return;
    }

    Node* newNode = new Node();
    newNode-> data = data;
    newNode-> next = current-> next;
    newNode-> prev = current;

    if (current-> next != nullptr)
        current-> next-> prev = newNode;
    else 
        tail = newNode;
}