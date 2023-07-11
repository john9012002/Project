#include <iostream>

using namespace std;

// Lớp SoPhuc
class SoPhuc {
private:
    double phanThuc;
    double phanAo;
public:
    SoPhuc() {
        phanThuc = 0;
        phanAo = 0;
    }
    SoPhuc(double pt, double pa) {
        phanThuc = pt;
        phanAo = pa;
    }
    void nhap() {
        cout << "Nhap phan thuc: ";
        cin >> phanThuc;
        cout << "Nhap phan ao: ";
        cin >> phanAo;
    }
    void xuat() {
        cout << phanThuc << " + " << phanAo << "i" << endl;
    }
    SoPhuc cong(SoPhuc sp) {
        SoPhuc ketQua;
        ketQua.phanThuc = phanThuc + sp.phanThuc;
        ketQua.phanAo = phanAo + sp.phanAo;
        return ketQua;
    }
    SoPhuc nhan(SoPhuc sp) {
        SoPhuc ketQua;
        ketQua.phanThuc = phanThuc * sp.phanThuc - phanAo * sp.phanAo;
        ketQua.phanAo = phanThuc * sp.phanAo + phanAo * sp.phanThuc;
        return ketQua;
    }
};

// Hàm main
int main() {
    SoPhuc sp1, sp2, ketQua;
    int luaChon;
    do {
        cout << "Menu" << endl;
        cout << "1. Nhap so phuc:" << endl;
        cout << "2. Hien thi so phuc" << endl;
        cout << "3. Cong 2 so phuc" << endl;
        cout << "4. Nhan 2 so phuc" << endl;
        cout<<  "5. Thoat"<<endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        switch (luaChon) {
            case 1:
                cout << "Nhap so phuc thu nhat:" << endl;
                sp1.nhap();
                cout << "Nhap so phuc thu hai:" << endl;
                sp2.nhap();
                break;
            case 2:
                cout << "So phuc thu nhat: ";
                sp1.xuat();
                cout << "So phuc thu hai: ";
                sp2.xuat();
                break;
            case 3:
                ketQua = sp1.cong(sp2);
                cout << "Tong 2 so phuc: ";
                ketQua.xuat();
                break;
            case 4:
                ketQua = sp1.nhan(sp2);
                cout << "Tich 2 so phuc: ";
                ketQua.xuat();
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