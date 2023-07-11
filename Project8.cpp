
#include <iostream>
#include <vector>

using namespace std;

class Nguoi {
protected:
    string hoTen;
    int tuoi;
    string queQuan;

public:
    Nguoi(string hoTen, int tuoi, string queQuan) {
        this->hoTen = hoTen;
        this->tuoi = tuoi;
        this->queQuan = queQuan;
    }

    string getHoTen() {
        return hoTen;
    }

    int getTuoi() {
        return tuoi;
    }

    string getQueQuan() {
        return queQuan;
    }
};

class Cbgv : public Nguoi {
private:
    string maSo;
    float luongCung;
    float luongThuong;
    float tienPhat;

public:
    Cbgv(string hoTen, int tuoi, string queQuan, string maSo, float luongCung, float luongThuong, float tienPhat) : Nguoi(hoTen, tuoi, queQuan) {
        this->maSo = maSo;
        this->luongCung = luongCung;
        this->luongThuong = luongThuong;
        this->tienPhat = tienPhat;
    }

    string getMaSo() {
        return maSo;
    }

    float tinhLuongThuc() {
        return luongCung + luongThuong - tienPhat;
    }
};

class Khoa {
private:
    vector<Cbgv> danhSachCbgv;

public:
    void themCbgv(Cbgv cbgv) {
        danhSachCbgv.push_back(cbgv);
    }

    void xoaCbgv(string maSo) {
        for (int i = 0; i < danhSachCbgv.size(); i++) {
            if (danhSachCbgv[i].getMaSo() == maSo) {
                danhSachCbgv.erase(danhSachCbgv.begin() + i);
                break;
            }
        }
    }

    void tinhLuongThuc(string maSo) {
        for (int i = 0; i < danhSachCbgv.size(); i++) {
            if (danhSachCbgv[i].getMaSo() == maSo) {
                cout << "Lương thực lĩnh của giáo viên " << danhSachCbgv[i].getHoTen() << " là: " << danhSachCbgv[i].tinhLuongThuc() << endl;
                return;
            }
        }
        cout << "Không tìm thấy giáo viên có mã số " << maSo << endl;
    }
};

int main() {
    Khoa khoa;

    Cbgv giangVien1("Nguyen Van A", 35, "Hanoi", "GV001", 5000000, 1000000, 500000);
    Cbgv giangVien2("Tran Thi B", 40, "Ho Chi Minh", "GV002", 6000000, 2000000, 100000);

    khoa.themCbgv(giangVien1);
    khoa.themCbgv(giangVien2);

    string maSoXoa;
    cout << "Nhap ma so giao vien can xoa: ";
    cin >> maSoXoa;
    khoa.xoaCbgv(maSoXoa);

    string maSoTinhLuong;
    cout << "Nhap ma so giao vien can tinh luong: ";
    cin >> maSoTinhLuong;
    khoa.tinhLuongThuc(maSoTinhLuong);

    return 0;
}

