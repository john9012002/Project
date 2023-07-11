#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SinhVien {
private:
    string hoTen;
    int tuoi;
    string lop;

public:
    SinhVien(string hoTen, int tuoi, string lop) {
        this->hoTen = hoTen;
        this->tuoi = tuoi;
        this->lop = lop;
    }

    string getHoTen() {
        return hoTen;
    }

    int getTuoi() {
        return tuoi;
    }

    string getLop() {
        return lop;
    }
};

class TheMuon {
private:
    string maPhieuMuon;
    int ngayMuon;
    int hanTra;
    int soHieuSach;
    SinhVien* sinhVienMuon;

public:
    TheMuon(string maPhieuMuon, int ngayMuon, int hanTra, int soHieuSach, SinhVien* sinhVienMuon) {
        this->maPhieuMuon = maPhieuMuon;
        this->ngayMuon = ngayMuon;
        this->hanTra = hanTra;
        this->soHieuSach = soHieuSach;
        this->sinhVienMuon = sinhVienMuon;
    }

    string getMaPhieuMuon() {
        return maPhieuMuon;
    }

    int getNgayMuon() {
        return ngayMuon;
    }

    int getHanTra() {
        return hanTra;
    }

    int getSoHieuSach() {
        return soHieuSach;
    }

    SinhVien* getSinhVienMuon() {
        return sinhVienMuon;
    }
};

class ThuVien {
private:
    vector<TheMuon*> danhSachTheMuon;

public:
    void themTheMuon(TheMuon* theMuon) {
        danhSachTheMuon.push_back(theMuon);
    }

    void xoaTheMuon(string maPhieuMuon) {
        for (int i = 0; i < danhSachTheMuon.size(); i++) {
            if (danhSachTheMuon[i]->getMaPhieuMuon() == maPhieuMuon) {
                danhSachTheMuon.erase(danhSachTheMuon.begin() + i);
                break;
            }
        }
    }

    void hienThiThongTinTheMuon() {
        for (int i = 0; i < danhSachTheMuon.size(); i++) {
            TheMuon* theMuon = danhSachTheMuon[i];
            SinhVien* sinhVienMuon = theMuon->getSinhVienMuon();

            cout << "Ma phieu muon: " << theMuon->getMaPhieuMuon() << endl;
            cout << "Ngay muon: " << theMuon->getNgayMuon() << endl;
            cout << "Han tra: " << theMuon->getHanTra() << endl;
            cout << "So hieu sach: " << theMuon->getSoHieuSach() << endl;
            cout << "Thong tin sinh vien muon sach: " << endl;
            cout << "Ho ten: " << sinhVienMuon->getHoTen() << endl;
            cout << "Tuoi: " << sinhVienMuon->getTuoi() << endl;
            cout << "Lop: " << sinhVienMuon->getLop() << endl;
            cout << endl;
        }
    }
};

int main() {
    SinhVien* sinhVien1 = new SinhVien("Nguyen Van A", 20, "K62CB");
    SinhVien* sinhVien2 = new SinhVien("Tran Thi B", 21, "K63CB");

    TheMuon* theMuon1 = new TheMuon("PM001", 1, 10, 123, sinhVien1);
    TheMuon* theMuon2 = new TheMuon("PM002", 2, 11, 456, sinhVien2);

    ThuVien thuVien;
    thuVien.themTheMuon(theMuon1);
    thuVien.themTheMuon(theMuon2);

    thuVien.hienThiThongTinTheMuon();

    thuVien.xoaTheMuon("PM001");

    thuVien.hienThiThongTinTheMuon();

    return 0;
}