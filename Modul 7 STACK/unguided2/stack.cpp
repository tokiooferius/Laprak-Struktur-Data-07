#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = 0;
}

bool isEmpty(Stack S) {
    return S.top == 0;
}

bool isFull(Stack S) {
    return S.top == MAX;
}

void push(Stack &S, int x) {
    if (isFull(S))
        cout << "Stack penuh!" << endl;
    else
        S.info[++S.top] = x;
}

int pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return 0;
    } else
        return S.info[S.top--];
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 1; i--)
            cout << S.info[i] << " ";
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}

// ======================
// Tambahan untuk Soal No. 2
// ======================
void pushAscending(Stack &S, int x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }

    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

// ======================
// Tambahan untuk Soal No. 3
// ======================
void getInputStream(Stack &S) {
    char x;
    cout << "Masukkan angka (akhiri dengan ENTER): ";
    while (cin.get(x) && x != '\n') {
        if (isdigit(x)) {
            int val = x - '0';
            push(S, val);
        }
    }
}
