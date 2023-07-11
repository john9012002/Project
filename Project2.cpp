#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Lớp cha Tài liệu
class TaiLieu {
protected:
    string maTaiLieu;
    string tenNhaXuatBan;
    int soBanPhatHanh;
public:
    TaiLieu(string ma, string tenNXB, int soBan) {
        maTaiLieu = ma;
        tenNhaXuatBan = tenNXB;
        soBanPhatHanh = soBan;
    }
    virtual void nhap() = 0;
    virtual void xuat() = 0;
    string getMaTaiLieu() {
        return maTaiLieu;
    }
};

// Lớp con Sách
class Sach : public TaiLieu {
private:
    string tenTacGia;
    int soTrang;
public:
    Sach(string ma, string tenNXB, int soBan, string tenTG, int soTr) : TaiLieu(ma, tenNXB, soBan) {
        tenTacGia = tenTG;
        soTrang = soTr;
    }
    void nhap() {
        cout << "Nhap thong tin sach:" << endl;
        cout << "Ma tai lieu: ";
        cin >> maTaiLieu;
        cout << "Ten nha xuat ban: ";
        cin >> tenNhaXuatBan;
        cout << "So ban phat hanh: ";
        cin >> soBanPhatHanh;
        cout << "Ten tac gia: ";
        cin >> tenTacGia;
        cout << "So trang: ";
        cin >> soTrang;
    }
    void xuat() {
        cout << "Ma tai lieu: " << maTaiLieu << endl;
        cout << "Ten nha xuat ban: " << tenNhaXuatBan << endl;
        cout << "So ban phat hanh: " << soBanPhatHanh << endl;
        cout << "Ten tac gia: " << tenTacGia << endl;
        cout << "So trang: " << soTrang << endl;
    }
};

// Lớp con Tạp chí
class TapChi : public TaiLieu {
private:
    int soPhatHanh;
    int thangPhatHanh;
public:
    TapChi(string ma, string tenNXB, int soBan, int soPH, int thangPH) : TaiLieu(ma, tenNXB, soBan) {
        soPhatHanh = soPH;
        thangPhatHanh = thangPH;
    }
    void nhap() {
        cout << "Nhap thong tin tap chi:" << endl;
        cout << "Ma tai lieu: ";
        cin >> maTaiLieu;
        cout << "Ten nha xuat ban: ";
        cin >> tenNhaXuatBan;
        cout << "So ban phat hanh: ";
        cin >> soBanPhatHanh;
        cout << "So phat hanh: ";
        cin >> soPhatHanh;
        // ... Tiếp tục phần giải pháp cho bài toán trước đó

        cout << "Thang phat hanh: ";
        cin >> thangPhatHanh;
    }
    void xuat() {
        cout << "Ma tai lieu: " << maTaiLieu << endl;
        cout << "Ten nha xuat ban: " << tenNhaXuatBan << endl;
        cout << "So ban phat hanh: " << soBanPhatHanh << endl;
        cout << "So phat hanh: " << soPhatHanh << endl;
        cout << "Thang phat hanh: " << thangPhatHanh << endl;
    }
};

// Lớp con Báo
class Bao : public TaiLieu {
private:
    string ngayPhatHanh;
public:
    Bao(string ma, string tenNXB, int soBan, string ngayPH) : TaiLieu(ma, tenNXB, soBan) {
        ngayPhatHanh = ngayPH;
    }
    void nhap() {
        cout << "Nhap thong tin bao:" << endl;
        cout << "Ma tai lieu: ";
        cin >> maTaiLieu;
        cout << "Ten nha xuat ban: ";
        cin >> tenNhaXuatBan;
        cout << "So ban phat hanh: ";
        cin >> soBanPhatHanh;
        cout << "Ngay phat hanh: ";
        cin >> ngayPhatHanh;
    }
    void xuat() {
        cout << "Ma tai lieu: " << maTaiLieu << endl;
        cout << "Ten nha xuat ban: " << tenNhaXuatBan << endl;
        cout << "So ban phat hanh: " << soBanPhatHanh << endl;
        cout << "Ngay phat hanh: " << ngayPhatHanh << endl;
    }
};

// Lớp QuanLySach
class QuanLySach {
private:
    vector<TaiLieu*> danhSachTaiLieu;
public:
    void themTaiLieu() {
        int loaiTaiLieu;
        cout << "Nhap loai tai lieu (1: Sach, 2: Tap chi, 3: Bao): ";
        cin >> loaiTaiLieu;
        TaiLieu* taiLieu;
        switch (loaiTaiLieu) {
            case 1:
                taiLieu = new Sach("", "", 0, "", 0);
                break;
            case 2:
                taiLieu = new TapChi("", "", 0, 0, 0);
                break;
            case 3:
                taiLieu = new Bao("", "", 0, "");
                break;
            default:
                cout << "Loai tai lieu khong hop le!" << endl;
                return;
        }
        taiLieu->nhap();
        danhSachTaiLieu.push_back(taiLieu);
        cout << "Them tai lieu thanh cong!" << endl;
    }
    void xoaTaiLieu() {
        string maTaiLieu;
        cout << "Nhap ma tai lieu can xoa: ";
        cin >> maTaiLieu;
        for (int i = 0; i < danhSachTaiLieu.size(); i++) {
            if (danhSachTaiLieu[i]->getMaTaiLieu() == maTaiLieu) {
                danhSachTaiLieu.erase(danhSachTaiLieu.begin() + i);
                cout << "Xoa tai lieu thanh cong!" << endl;
                return;
            }
        }
        cout << "Khong tim thay tai lieu co ma " << maTaiLieu << endl;
    }
    void hienThiThongTin() {
        for (int i = 0; i < danhSachTaiLieu.size(); i++) {
            danhSachTaiLieu[i]->xuat();
            cout << endl;
        }
    }
    void timKiemTaiLieu() {
        int loaiTaiLieu;
        cout << "Nhap loai tai lieu can tim kiem (1: Sach, 2: Tap chi, 3: Bao): ";
        cin >> loaiTaiLieu;
        for (int i = 0; i < danhSachTaiLieu.size(); i++) {
            if (loaiTaiLieu == 1 && dynamic_cast<Sach*>(danhSachTaiLieu[i])) {
                danhSachTaiLieu[i]->xuat();
                cout << endl;
            }
            else if (loaiTaiLieu == 2 && dynamic_cast<TapChi*>(danhSachTaiLieu[i])) {
                danhSachTaiLieu[i]->xuat();
                cout << endl;
            }
            else if (loaiTaiLieu == 3 && dynamic_cast<Bao*>(danhSachTaiLieu[i])) {
                danhSachTaiLieu[i]->xuat();
                cout << endl;
            }
        }
    }
};

// Hàm main
int main() {
    QuanLySach quanLySach;
    int luaChon;
    do {
        cout << "Menu:" << endl;
        cout << "1. Sach:" << endl;
        cout << "2. Tap Chi" << endl;
        cout << "3. Bao" << endl;
        cout << "4. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        switch (luaChon) {
            case 1:
                quanLySach.themTaiLieu();
                break;
            case 2:
                quanLySach.xoaTaiLieu();
                break;
            case 3:
                quanLySach.hienThiThongTin();
                break;
            case 4:
                quanLySach.timKiemTaiLieu();
                break;
            case 5:
                cout << "Tam biet!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
    } while (luaChon != 5);
    return 0;
}