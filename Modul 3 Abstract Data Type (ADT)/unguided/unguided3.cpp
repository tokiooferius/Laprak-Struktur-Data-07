#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
    int x = 10, y = 20;
    int *p1 = &x, *p2 = &y;

    cout << "Array A:\n"; tampilArray(A);
    cout << "Array B:\n"; tampilArray(B);

    tukarArray(A, B, 1, 1); // tukar elemen di posisi [1][1]
    cout << "\nSetelah ditukar elemen tengah:\n";
    cout << "Array A:\n"; tampilArray(A);
    cout << "Array B:\n"; tampilArray(B);

    cout << "\nNilai sebelum tukar pointer: x=" << x << ", y=" << y << endl;
    tukarPointer(p1, p2);
    cout << "Nilai setelah tukar pointer: x=" << x << ", y=" << y << endl;

    return 0;
}