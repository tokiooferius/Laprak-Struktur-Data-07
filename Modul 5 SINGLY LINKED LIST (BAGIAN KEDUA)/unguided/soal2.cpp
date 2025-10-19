#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judul, penulis, isbn;
    Buku* next;
};

Buku* head = nullptr;

void tambahBuku(string judul, string penulis, string isbn) {
    Buku* newBuku = new Buku();
    newBuku->judul = judul;
    newBuku->penulis = penulis;
    newBuku->isbn = isbn;
    newBuku->next = nullptr;

    if (head == nullptr)
        head = newBuku;
    else {
        Buku* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newBuku;
    }

    cout << "Buku '" << judul << "' berhasil ditambahkan.\n";
}

void tampilkanBuku() {
    if (head == nullptr) {
        cout << "Tidak ada data buku.\n";
        return;
    }

    Buku* temp = head;
    cout << "\nDaftar Buku:\n";
    while (temp != nullptr) {
        cout << "- " << temp->judul << " | " << temp->penulis 
             << " | ISBN: " << temp->isbn << endl;
        temp = temp->next;
    }
}

void cariBuku(string keyword) {
    Buku* temp = head;
    bool ditemukan = false;

    while (temp != nullptr) {
        if (temp->judul == keyword || temp->penulis == keyword || temp->isbn == keyword) {
            cout << "Buku ditemukan: " << temp->judul << " | " 
                 << temp->penulis << " | ISBN: " << temp->isbn << endl;
            ditemukan = true;
        }
        temp = temp->next;
    }

    if (!ditemukan)
        cout << "Data buku dengan keyword '" << keyword << "' tidak ditemukan.\n";
}

int main() {
    int pilihan;
    string judul, penulis, isbn, keyword;

    do {
        cout << "\n=== MENU DATA BUKU ===\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Buku\n";
        cout << "3. Cari Buku\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Judul: ";
                getline(cin >> ws, judul);    
                cout << "Penulis: ";
                getline(cin, penulis);
                cout << "ISBN: ";
                getline(cin, isbn);
                tambahBuku(judul, penulis, isbn);
                break;
            case 2:
                tampilkanBuku();
                break;
            case 3:
                cout << "Masukkan keyword (judul/penulis/ISBN): ";
                getline(cin >> ws, keyword);
                cariBuku(keyword);
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
