#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Lớp cơ sở CanBo
class CanBo {
protected:
    string hoTen;
    int tuoi;
    string gioiTinh;
    string diaChi;
public:
    CanBo() {}
    CanBo(string hoTen, int tuoi, string gioiTinh, string diaChi) {
        this->hoTen = hoTen;
        this->tuoi = tuoi;
        this->gioiTinh = gioiTinh;
        this->diaChi = diaChi;
    }
    virtual void nhapThongTin() {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cin.ignore();
        cout << "Nhap gioi tinh: ";
        getline(cin, gioiTinh);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
    }
    virtual void xuatThongTin() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Gioi tinh: " << gioiTinh << endl;
        cout << "Dia chi: " << diaChi << endl;
    }
    string getHoTen() {
        return hoTen;
    }
};

// Lớp CongNhan kế thừa từ lớp CanBo
class CongNhan : public CanBo {
private:
    int bac;
public:
    CongNhan() {}
    CongNhan(string hoTen, int tuoi, string gioiTinh, string diaChi, int bac) : CanBo(hoTen, tuoi, gioiTinh, diaChi) {
        this->bac = bac;
    }
    void nhapThongTin() {
        CanBo::nhapThongTin();
        cout << "Nhap bac: ";
        cin >> bac;
        cin.ignore();
    }
    void xuatThongTin() {
        CanBo::xuatThongTin();
        cout << "Bac: " << bac << endl;
    }
};

// Lớp KySu kế thừa từ lớp CanBo
class KySu : public CanBo {
private:
    string nganhDaoTao;
public:
    KySu() {}
    KySu(string hoTen, int tuoi, string gioiTinh, string diaChi, string nganhDaoTao) : CanBo(hoTen, tuoi, gioiTinh, diaChi) {
        this->nganhDaoTao = nganhDaoTao;
    }
    void nhapThongTin() {
        CanBo::nhapThongTin();
        cout << "Nhap nganh dao tao: ";
        getline(cin, nganhDaoTao);
    }
    void xuatThongTin() {
        CanBo::xuatThongTin();
        cout << "Nganh dao tao: " << nganhDaoTao << endl;
    }
};

// Lớp NhanVien kế thừa từ lớp CanBo
class NhanVien : public CanBo {
private:
    string congViec;
public:
    NhanVien() {}
    NhanVien(string hoTen, int tuoi, string gioiTinh, string diaChi, string congViec) : CanBo(hoTen, tuoi, gioiTinh, diaChi) {
        this->congViec = congViec;
    }
    void nhapThongTin() {
        CanBo::nhapThongTin();
        cout << "Nhap cong viec: ";
        getline(cin, congViec);
    }
    void xuatThongTin() {
        CanBo::xuatThongTin();
        cout << "Cong viec: " << congViec << endl;
    }
};

// Lớp QLCB để quản lý các cán bộ
class QLCB {
private:
    vector<CanBo*> danhSachCanBo;
public:
    void themMoiCanBo() {
        int loaiCanBo;
        cout << "Nhap loai can bo (1: Cong nhan, 2: Ky su, 3: Nhan vien): ";
        cin >> loaiCanBo;
        cin.ignore();
        CanBo* canBo;
        switch (loaiCanBo) {
            case 1:
                canBo = new CongNhan();
                break;
            case 2:
                canBo = new KySu();
                break;
            case 3:
                canBo = new NhanVien();
                break;
            default:
                cout << "Loai can bo khong hop le!" << endl;
                return;
        }
        canBo->nhapThongTin();
        danhSachCanBo.push_back(canBo);
        cout << "Them moi can bo thanh cong!" << endl;
    }
    void timKiemCanBo() {
        string hoTen;
        cout << "Nhap ho ten can bo can tim kiem: ";
        getline(cin, hoTen);
        bool timThay = false;
        for (CanBo* canBo : danhSachCanBo) {
            if (canBo->getHoTen() == hoTen) {
                canBo->xuatThongTin();
                timThay = true;
            }
        }
        if (!timThay) {
            cout << "Khong tim thay can bo co ho ten la " << hoTen << endl;
        }
    }
    void hienThiDanhSachCanBo() {
        for (CanBo* canBo : danhSachCanBo) {
            canBo->xuatThongTin();
            cout << endl;
        }
    }
};

// Hàm main để chạy chương trình
int main() {
    QLCB qlcb;
    int luaChon;
    do {
        cout << "Menu:" << endl;
        cout << "1. Them moi can bo" << endl;
        cout << "2. Tim kiem can bo" << endl;
        cout << "3. Hien thi danh sach can bo" << endl;
        cout << "4. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        cin.ignore();
        switch (luaChon) {
            case 1:
                qlcb.themMoiCanBo();
                break;
            case 2:
                qlcb.timKiemCanBo();
                break;
            case 3:
                qlcb.hienThiDanhSachCanBo();
                break;
            case 4:
                cout << "Tam biet!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
        }
    } while (luaChon != 4);
    return 0;
}