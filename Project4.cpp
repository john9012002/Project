#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Nguoi {
private:
    string hoTen;
    int tuoi;
    string cmnd;
public:
    // Hàm tạo
    Nguoi(string hoTen, int tuoi, string cmnd) {
        this->hoTen = hoTen;
        this->tuoi = tuoi;
        this->cmnd = cmnd;
    }
    
    // Getter
    string getCMND() {
        return cmnd;
    }
};

class KhachSan {
private:
    vector<Nguoi> khachThue;
public:
    // Phương thức thêm mới khách thuê phòng
    void themKhachThue(Nguoi khach) {
        khachThue.push_back(khach);
    }
    
    // Phương thức xóa khách thuê phòng dựa vào số CMND
    void xoaKhachThue(string cmnd) {
        for (int i = 0; i < khachThue.size(); i++) {
            if (khachThue[i].getCMND() == cmnd) {
                khachThue.erase(khachThue.begin() + i);
                cout << "Xoa khach thanh cong!\n";
                return;
            }
        }
        cout << "Khach khong ton tai!\n";
    }
    
    // Tính tiền thuê phòng cho khách dựa vào số CMND
    void tinhTienThuePhong(string cmnd, int soNgayThue, string loaiPhong) {
        int giaPhong;
        if (loaiPhong == "a")
            giaPhong = 500;
        else if (loaiPhong == "b")
            giaPhong = 300;
        else if (loaiPhong == "c")
            giaPhong = 100;
        else {
            cout << "Loai phong khong hop le!\n";
            return;
        }
        
        for (int i = 0; i < khachThue.size(); i++) {
            if (khachThue[i].getCMND() == cmnd) {
                cout << "Tien thue phong: " << soNgayThue * giaPhong << "$\n";
                return;
            }
        }
        cout << "Khach khong ton tai!\n";
    }
};

int main() {
    KhachSan khachSan;
    
    // Khởi tạo và thêm mới khách thuê phòng
    Nguoi khach1("Nguyen Van A", 25, "111111111");
    Nguoi khach2("Tran Thi B", 30, "222222222");
    Nguoi khach3("Le Van C", 35, "333333333");
    
    khachSan.themKhachThue(khach1);
    khachSan.themKhachThue(khach2);
    khachSan.themKhachThue(khach3);
    
    // Test tính tiền thuê phòng
    khachSan.tinhTienThuePhong("111111111", 7, "a");
    khachSan.tinhTienThuePhong("222222222", 5, "b");
    khachSan.tinhTienThuePhong("333333333", 3, "c");
    
    // Test xóa khách thuê
    khachSan.xoaKhachThue("222222222");
    
    return 0;
}

