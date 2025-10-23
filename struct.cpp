#include <iostream>
#include <string>
#include <fstream> // menyimpan data
#include <vector>
#include <sstream>
using namespace std;

  
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
    struct MapelNilai {
    float mtk;
    float bin;
    float big;
    float ipa;
    };
    struct siswa {
    string nama;
    string NISN;
    string jurusan;
    nilai Nilai; //ini struct di dalam struct
    float total; // nilai akhir
    };

//input&tampil
void inputMahasiswa(Mahasiswa &m1) {
    cout << "masukkan nama : ";
    getline(cin, m1.nama);
    cout << "masukkan umur : ";
    cin >> m1.umur;
    cin.ignore();
    cout << "masukkan jurusan : ";
    getline(cin, m1.jurusan);
   }
    void tampilkanMahasiswa(const Mahasiswa &m1) {
    cout << "nama : " << m1.nama<<endl;
    cout << "umur : " << m1.umur <<endl;
    cout << "jurusan : " << m1.jurusan <<endl;
    }
    void inputMahasiswa(Mahasiswa &m2) {
    cout << "masukkan nama : ";
    getline(cin, m2.nama);
    cout << "masukkan umur : ";
    cin >> m2.umur;
    cin.ignore();
    cout << "masukkan jurusan : ";
    getline(cin, m2.jurusan);

    void tampilkanMahasiswa(const Mahasiswa &m2) {
    cout << "nama : " << m2.nama <<endl;
    cout << "umur : " << m2.umur <<endl;
    cout << "jurusan : " << m2.jurusan <<endl;

    lahir = inputTanggal(); {
    TanggalLahir f;
    cout << "masukkan hari : ";
    cin >> lahir.hari;
    cout << "masukkan bulan : ";
    cin >> lahir.bulan;
    cout << "masukkan tahun : ";
    cin >> lahir.tahun;
    }

    cout << lahir.hari << "-" << lahir.bulan << "-" << lahir.tahun << endl;


    Nilai inputNilai() {
    nilai x;
    cout << "masukkan nilai uts : ";
    cin >> nilai.uts;
    cout << "masukkan nilai uas : ";
    cin >> nilai.uas;
    cout << "masukkan tugas : ";
    cin >> nilai.tugas;
    return x;
    }
  
    void tambahkanSiswa() {
     ofstream file("siswa.txt", ios::app);
     Siswa r;
     cout << "masukkan nama siswa: ";
     getline(cin, s.nama);
     cout << "masukkan NISN: ";
     getline(cin, s.NISN);
     cout << "masukkan jurusan: ";
     getline(cin, s.jurusan);

     cout << "masukkan nilai matematika: ";
     cin >> s.nilai.mtk;
     cout << "masukkan nilai b.indo: ";
     cin >> s.nilai.bin;
     cout << "masukkan nilai ipa: ";
     cin  >> s.nilai.ipa;
      
     s.total = (s.Nilai.Mtk * 0.4) + (s.Nilai.IPA * 0.3) + (s.Nilai.BIn * 0.2) + (s.Nilai.Big * 0.1);
      
     //simpan ke file
     file << s.nama << "|" << s.NISN << "|" << s.jurusan << "|" << s.nilai.mtk << "|" << s.nilai.bin << "|" << s.nilai.big << "|" << s.nilai.ipa << "\n";
     file.close();
      
     cout << "data siswa berhasil disimpan;
     }
     void tampikanlDataSiswa() {
     ifstream file("siswa.txt");
     if (!file) {
        cout << "Belum ada data siswa";
        return;
     }
     cout << "Daftar Data Siswa";
     string line;
     while (getline(file, line)) {
        cout << line << endl;
     }
     file.close();
     }

     //cari siswa pada NISN
     void cariSiswa() {
     ifstream file("siswa.txt");
     if (!file) {
        cout << "File tidak ditemukan.";
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

     if (!ketemu) cout << " Data dengan NISN " << nisn << " tidak ditemukan.\n";
     file.close();
     }
      
    //menghitung nilai akhir
    float nilaiAkhir(const nilai &n) {
    return (n.Mtk * 0.4) + (n.IPA * 0.3) + (n.BIn * 0.2) + (n.Big * 0.1);
   }

   // rangking siswa
   void ranking() {
   ifstream file("siswa.txt");
   if (!file) {
   cout << "File 'siswa.txt' tidak ditemukan";
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

    cout << "PERINGKAT SISWA BERDASARKAN NILAI AKHIR";
    int peringkat = 1;
    for (auto &s : daftar) {
        cout << peringkat++ << ". " << s.nama
             << " (" << s.NISN << ") - Nilai Akhir: " << s.total << endl;
     }
    }
    void ranking() {
    ifstream file("siswa.txt");
    if (!file) {
        cout << "Belum ada data siswa.\n";
        return;
    }

    vector<pair<string, float>> daftar;
    string data;

    while (getline(file, data)) {
    size_t pos = 0;
    vector<string> bagian;
    while ((pos = data.find('|')) != string::npos) {
    bagian.push_back(data.substr(0, pos));
    data.erase(0, pos + 1);
    }
      
    bagian.push_back(data);

    if (bagian.size() == 7) {
    Nilai n;
    n.Mtk = stof(bagian[3]);
    n.BIn = stof(bagian[4]);
    n.Big = stof(bagian[5]);
    n.IPA = stof(bagian[6]);
    daftar.push_back({bagian[0], nilaiAkhir(n)});
        }
    }
      
    file.close();  
    sort(daftar.begin(), daftar.end(), // Urutkan ranking dari nilai tertinggi ke terendah
    [](auto &a, auto &b) { return a.second > b.second; });

    cout << "\n=== RANKING SISWA ===\n";
    int peringkat = 1;
    for (auto &d : daftar) {
        cout << peringkat++ << ". " << d.first << " - Nilai Akhir: " << d.second << endl;
    }
  }

      //main program
    int main()
      
    mahasiswa m1, m2;
    Nilai nilai;
    TanggalLahir Lahir;

    inputMahasiswa(m1, 1)
    inputMahasiswa(m2, 2);

    tampilkanMahasiswa(m1, 1)
    tampilkanMahasiswa(m2, 2)

    nilai = inputNilai();
    float nilai_final = nilai.uas * 0.4 + nilai.uts * 0.35 + nilai.tugas * 0.25;

    cout << "nilai uts : " << nilai.uts << endl;
    cout << "nilai uas : " << nilai.uas << endl;
    cout << "nilai tugas : " << nilai.tugas << endl;
    cout << "nilai final : " << nilai_final << endl;

    int pilih;
    do {
    cout << "1. tambahkan data siswa" << endl;
    cout << "2. tampilkan data siswa" << endl;
    cout << "3. cari berdasarkan NISN" << endl;
    cout << "4.tampilkan ranking siswa" << endl;
    cout << "5. keluar" << endl;
    cout << "pilih angka (1-5): ";
    cin >> pilih;

    switch (pilih) {
    case 1: tambahkanDataSiswa(); break;
    case 2: tampilkanDataSiswa(); break;
    case 3: cariSiswa(); break;
    case 4: rangking(); break;
    case 5: cout << "terimakasih!;break;
    default: cout  << "pilihan tidak valid\n;
    }
      } while (pilih !=5);
    

    return 0;
}
