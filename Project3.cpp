#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Lớp Nguoi
class Nguoi {
private:
    string hoTen;
    int tuoi;
    string ngheNghiep;
    string soCMND;
public:
    Nguoi(string ht, int t, string nn, string cmnd) {
        hoTen = ht;
        tuoi = t;
        ngheNghiep = nn;
        soCMND = cmnd;
    }
    void xuat() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Nghe nghiep: " << ngheNghiep << endl;
        cout << "So CMND: " << soCMND << endl;
    }
};

// Lớp HoGiaDinh
class HoGiaDinh {
private:
    int soThanhVien;
    int soNha;
    vector<Nguoi*> danhSachNguoi;
public:
    HoGiaDinh(int stv, int sn) {
        soThanhVien = stv;
        soNha = sn;
    }
    void themNguoi() {
        string hoTen, ngheNghiep, soCMND;
        int tuoi;
        cout << "Nhap thong tin nguoi:" << endl;
        cout << "Ho ten: ";
        cin >> hoTen;
        cout << "Tuoi: ";
        cin >> tuoi;
        cout << "Nghe nghiep: ";
        cin >> ngheNghiep;
        cout << "So CMND: ";
        cin >> soCMND;
        Nguoi* nguoi = new Nguoi(hoTen, tuoi, ngheNghiep, soCMND);
        danhSachNguoi.push_back(nguoi);
        cout << "Them nguoi thanh cong!" << endl;
    }
    void xuat() {
        cout << "So thanh vien: " << soThanhVien << endl;
        cout << "So nha: " << soNha << endl;
        for (int i = 0; i < danhSachNguoi.size(); i++) {
            danhSachNguoi[i]->xuat();
            cout << endl;
        }
    }
};

// Lớp KhuPho
class KhuPho {
private:
    vector<HoGiaDinh*> danhSachHoGiaDinh;
public:
    void nhap() {
        int n;
        cout << "Nhap so ho gia dinh: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            int soThanhVien, soNha;
            cout << "Nhap thong tin ho gia dinh thu " << i + 1 << ":" << endl;
            cout << "So thanh vien: ";
            cin >> soThanhVien;
            cout << "So nha: ";
            cin >> soNha;
            HoGiaDinh* hoGiaDinh = new HoGiaDinh(soThanhVien, soNha);
            for (int j = 0; j < soThanhVien; j++) {
                hoGiaDinh->themNguoi();
            }
            danhSachHoGiaDinh.push_back(hoGiaDinh);
            cout << endl;
        }
    }
    void xuat() {
        for (int i = 0; i < danhSachHoGiaDinh.size(); i++) {
            danhSachHoGiaDinh[i]->xuat();
            cout << endl;
        }
    }
};

// Hàm main
int main() {
    KhuPho khuPho;
    khuPho.nhap();
    khuPho.xuat();
    return 0;
}