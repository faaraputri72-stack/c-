#include <iostream>
#include <string>
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

int main() {
    Mahasiswa m1,m2;

    cout << "masukkan nama : ";
    getline(cin, m1.nama);
    cout << "masukkan umur : ";
    cin >> m1.umur;
    cin.ignore();
    cout << "masukkan jurusan : ";
    getline(cin, m1.jurusan);


    cout << "nama : " << m1.nama<<endl;
    cout << "umur : " << m1.umur <<endl;
    cout << "jurusan : " << m1.jurusan <<endl;

cout << "masukkan nama : ";
    getline(cin, m2.nama);
    cout << "masukkan umur : ";
    cin >> m2.umur;
    cin.ignore();
    cout << "masukkan jurusan : ";
    getline(cin, m2.jurusan);

    cout << "nama : " << m2.nama <<endl;
    cout << "umur : " << m2.umur <<endl;
    cout << "jurusan : " << m2.jurusan <<endl;

    TanggalLahir lahir;
    cout << "masukkan hari : ";
    cin >> lahir.hari;
    cout << "masukkan bulan : ";
    cin >> lahir.bulan;
    cout << "masukkan tahun : ";
    cin >> lahir.tahun;

    cout << lahir.hari << "-" << lahir.bulan << "-" << lahir.tahun << endl;


    Nilai nilai;

    cout << "masukkan nilai uts : ";
    cin >> nilai.uts;
    cout << "masukkan nilai uas : ";
    cin >> nilai.uas;
    cout << "masukkan tugas : ";
    cin >> nilai.tugas;

    float nilai_final = nilai.uas * 0.4 + nilai.uts * 0.35 + nilai.tugas * 0.25;

    cout << nilai.uts << endl;
    cout << nilai.uas << endl;
    cout << nilai.tugas << endl;
    cout << nilai_final << endl;

    return 0;
}
