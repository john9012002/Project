#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Lớp HocSinh
class HocSinh {
private:
    string hoTen;
    int tuoi;
    string queQuan;
    string lop;
public:
    HocSinh(string ht, int t, string qq, string l) {
        hoTen = ht;
        tuoi = t;
        queQuan = qq;
        lop = l;
    }
    void xuat() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Que quan: " << queQuan << endl;
        cout << "Lop: " << lop << endl;
    }
    int getTuoi() {
        return tuoi;
    }
    string getQueQuan() {
        return queQuan;
    }
};

// Hàm main
int main() {
    vector<HocSinh*> danhSachHocSinh;
    int luaChon;
    do {
        cout << "Menu:" << endl;
        cout << "1. Them hoc sinh:" << endl;
        cout << "2. Hien thi hoc sinh 20 tuoi" << endl;
        cout << "3. Dem hoc sinh 23 tuoi" << endl;
        cout << "4. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        switch (luaChon) {
            case 1: {
                string hoTen, queQuan, lop;
                int tuoi;
                cout << "Nhap thong tin hoc sinh:" << endl;
                cout << "Ho ten: ";
                cin >> hoTen;
                cout << "Tuoi: ";
                cin >> tuoi;
                cout << "Que quan: ";
                cin >> queQuan;
                cout << "Lop: ";
                cin >> lop;
                HocSinh* hocSinh = new HocSinh(hoTen, tuoi, queQuan, lop);
                danhSachHocSinh.push_back(hocSinh);
                cout << "Them hoc sinh thanh cong!" << endl;
                break;
            }
            case 2: {
                cout << "Danh sach hoc sinh 20 tuoi:" << endl;
                for (int i = 0; i < danhSachHocSinh.size(); i++) {
                    if (danhSachHocSinh[i]->getTuoi() == 20) {
                        danhSachHocSinh[i]->xuat();
                        cout << endl;
                    }
                }
                break;
            }
            case 3: {
                int dem = 0;
                for (int i = 0; i < danhSachHocSinh.size(); i++) {
                    if (danhSachHocSinh[i]->getTuoi() == 23 && danhSachHocSinh[i]->getQueQuan() == "DN") {
                        dem++;
                    }
                }
                cout << "So luong hoc sinh 23 tuoi va que o DN: " << dem << endl;
                break;
            }
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