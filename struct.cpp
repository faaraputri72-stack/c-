#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// ====================== STRUCT DASAR ======================
struct TanggalLahir {
    string hari;
    string bulan;
    int tahun;
};

struct Nilai {
    float uts;
    float uas;
    float tugas;
};

struct Mahasiswa {
    string nama;
    int umur;
    string jurusan;
};

struct nilai {
    float Mtk;
    float BIn;
    float Big;
    float IPA;
};

struct siswa {
    string nama;
    string NISN;
    string jurusan;
    nilai Nilai; // struct di dalam struct
    float total; // nilai akhir
};

// input tampil mahasiswa
void inputMahasiswa(Mahasiswa &m1) {
    cout << "Masukkan nama  : ";
    getline(cin, m1.nama);
    cout << "Masukkan umur  : ";
    cin >> m1.umur;
    cin.ignore();
    cout << "Masukkan jurusan : ";
    getline(cin, m1.jurusan);
}

void tampilkanMahasiswa(const Mahasiswa &m1) {
    cout << "data mahasiswa";
    cout << "Nama  : " << m1.nama << endl;
    cout << "Umur  : " << m1.umur << endl;
    cout << "Jurusan : " << m1.jurusan << endl;
}

// input nilai
Nilai inputNilai() {
    Nilai x;
    cout << "\nMasukkan nilai UTS  : ";
    cin >> x.uts;
    cout << "Masukkan nilai UAS   : ";
    cin >> x.uas;
    cout << "Masukkan nilai Tugas : ";
    cin >> x.tugas;
    return x;
}

// fitur file
void tambahDataSiswa() {
    ofstream file("siswa.txt", ios::app); // append mode

    siswa s;
    cout << "\n=== Tambah Data Siswa ===\n";
    cin.ignore();
    cout << "Nama Siswa : ";
    getline(cin, s.nama);
    cout << "NISN       : ";
    getline(cin, s.NISN);
    cout << "Jurusan    : ";
    getline(cin, s.jurusan);
    cout << "Nilai Matematika : ";
    cin >> s.Nilai.Mtk;
    cout << "Nilai Bahasa Indonesia : ";
    cin >> s.Nilai.BIn;
    cout << "Nilai Bahasa Inggris : ";
    cin >> s.Nilai.Big;
    cout << "Nilai IPA : ";
    cin >> s.Nilai.IPA;

    s.total = (s.Nilai.Mtk * 0.4) + (s.Nilai.IPA * 0.3) + (s.Nilai.BIn * 0.2) + (s.Nilai.Big * 0.1);

    // Simpan ke file
    file << s.nama << "|" << s.NISN << "|" << s.jurusan << "|"
         << s.Nilai.Mtk << "|" << s.Nilai.BIn << "|" << s.Nilai.Big << "|" << s.Nilai.IPA << "|" << s.total << endl;
    file.close();

    cout << "Data siswa berhasil disimpan!\n";
}

void tampilDataSiswa() {
    ifstream file("siswa.txt");
    if (!file) {
    cout << "File 'siswa.txt' belum ada atau kosong!\n";
    return;
    }

    cout << "\n=== Daftar Data Siswa ===\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
   }

// cari siswa berdasarkan NISN
void cariSiswa() {
    ifstream file("siswa.txt");
    if (!file) {
        cout << "\nFile tidak ditemukan.\n";
        return;
    }

    string nisn, line;
    cout << "Masukkan NISN yang dicari: ";
    cin.ignore();
    getline(cin, nisn);

    bool ketemu = false;
    while (getline(file, line)) {
    if (line.find(nisn) != string::npos) {
    cout << "\nData ditemukan: " << line << endl;
    ketemu = true;
    break;
        }
    }

    if (!ketemu) cout << "Data dengan NISN " << nisn << " tidak ditemukan.\n";
    file.close();
}

   // hitung nilai akhir
   float nilaiAkhir(const nilai &n) {
   return (n.Mtk * 0.4) + (n.IPA * 0.3) + (n.BIn * 0.2) + (n.Big * 0.1);
}

   // FITUR RANGKING
   void ranking() {
     ifstream file("siswa.txt");
     if (!file) {
     cout << "\nFile 'siswa.txt' tidak ditemukan.\n";
     return;
     }

     vector<siswa> daftar;
     string line;

    while (getline(file, line)) {
        siswa s;
        stringstream ss(line);
        string temp;

        getline(ss, s.nama, '|');
        getline(ss, s.NISN, '|');
        getline(ss, s.jurusan, '|');

        getline(ss, temp, '|'); s.Nilai.Mtk = stof(temp);
        getline(ss, temp, '|'); s.Nilai.BIn = stof(temp);
        getline(ss, temp, '|'); s.Nilai.Big = stof(temp);
        getline(ss, temp, '|'); s.Nilai.IPA = stof(temp);
        getline(ss, temp, '|'); s.total = stof(temp);

        daftar.push_back(s);
   }
        file.close();

       // Urutkan berdasarkan nilai total (descending)
        sort(daftar.begin(), daftar.end(), [](siswa a, siswa b) {
        return a.total > b.total;
    });

        cout << "\nPERINGKAT SISWA BERDASARKAN NILAI AKHIR\n";
        int peringkat = 1;
        for (auto &s : daftar) {
        cout << peringkat++ << ". " << s.nama
        << " (" << s.NISN << ") - Nilai Akhir: " << s.total << endl;
             }
         }

        // main program
      int main() {
      Mahasiswa m1;
      Nilai nilaiMhs;

     cout << "PROGRAM DATA MAHASISWA & SISWA ";
     inputMahasiswa(m1);
     tampilkanMahasiswa(m1);

     nilaiMhs = inputNilai();
     float nilai_final = nilaiMhs.uas * 0.4 + nilaiMhs.uts * 0.35 + nilaiMhs.tugas * 0.25;

     cout << "\nNilai Akhir Mahasiswa: " << nilai_final << endl;

     int pilih;
     do {
        cout << "---> data siswa <---";
        cout << "1. Tambah Data Siswa\n";
        cout << "2. Tampilkan Semua Data Siswa\n";
        cout << "3. Cari Data Siswa (berdasarkan NISN)\n";
        cout << "4. Tampilkan Peringkat Siswa\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
        case 1: tambahDataSiswa();
                break;
        case 2: tampilDataSiswa();
                break;
       case 3: cariSiswa();
                break;
       case 4: ranking();
                break;
      case 5: cout << "Terimakasih!\n";
                break;
            default:
      cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 5);

    return 0;
}
