#include <iostream>
using namespace std;

int main() {
int matriks[3][3] = {
{1, 2, 3},
{4, 5, 6},
{7, 8, 9}
};

int transpose[3][3];

for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
transpose[j][i] = matriks[i][j];
}
}

cout << "Matriks Awal:\n";
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
cout << matriks[i][j] << " ";
}
cout << endl;
}

cout << "\nMatriks Hasil Transpose:\n";
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
cout << transpose[i][j] << " ";
}
cout << endl;
}

return 0;
}