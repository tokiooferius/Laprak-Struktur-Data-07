#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void tambahNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void tampilkanList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL\n";
}

Node* reverseList(Node* node) {
    Node* prev = nullptr;
    Node* current = node;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    tambahNode(3);
    tambahNode(2);
    tambahNode(1);

    cout << "List Awal: ";
    tampilkanList(head);

    head = reverseList(head);

    cout << "List Setelah Dibalik: ";
    tampilkanList(head);

    return 0;
}
