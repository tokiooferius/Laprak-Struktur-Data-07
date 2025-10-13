#include <iostream>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilai_akhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

void tampilkanData(Mahasiswa mhs[], int jumlah) {
    cout << "\nDaftar Nilai Mahasiswa:\n";
    cout << left << setw(15) << "Nama"
         << setw(15) << "NIM"
         << setw(10) << "UTS"
         << setw(10) << "UAS"
         << setw(10) << "Tugas"
         << setw(15) << "Nilai Akhir" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << left << setw(15) << mhs[i].nama
             << setw(15) << mhs[i].nim
             << setw(10) << mhs[i].uts
             << setw(10) << mhs[i].uas
             << setw(10) << mhs[i].tugas
             << setw(15) << fixed << setprecision(2) << mhs[i].nilai_akhir
             << endl;
    }
}

int main() {
    Mahasiswa mhs[10];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> jumlah;

    if (jumlah > 10) jumlah = 10;

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin >> mhs[i].nama;
        cout << "NIM    : ";
        cin >> mhs[i].nim;
        cout << "UTS    : ";
        cin >> mhs[i].uts;
        cout << "UAS    : ";
        cin >> mhs[i].uas;
        cout << "Tugas  : ";
        cin >> mhs[i].tugas;

        mhs[i].nilai_akhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    tampilkanData(mhs, jumlah);

    return 0;
}