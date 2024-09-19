#include <iostream>
#include <string>

using namespace std;

struct KhachHang {
    int maKhachHang;
    string tenKhachHang;
    string soDienThoai;
    float tongTienThanhToan;
};

void nhapKhachHang (KhachHang kh[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "o Nhap thong tin khach thu " << i + 1 << ": " << endl;
        
        cout << " - Ma khach hang: ";
        cin >> kh[i].maKhachHang;

        cin.ignore();
        cout << " - Ten khach hang: ";
        getline(cin, kh[i].tenKhachHang);

        cout << " - So dien thoai: ";
        getline(cin, kh[i].soDienThoai);

        cout << " - Tong tien thanh toan: ";
        cin >> kh[i].tongTienThanhToan;
    }
}

void xuatKhachHang(KhachHang kh[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "o Thong tin khach hang thu " << i + 1 << ": " << endl;
        cout << " - Ma khach hang: " << kh[i].maKhachHang << endl;
        cout << " - Ten khach hang: " << kh[i].tenKhachHang << endl;
        cout << " - So dien thoai: " << kh[i].soDienThoai << endl;
        cout << " - Tong tien thanh toan: " << kh[i].tongTienThanhToan << endl;
    }
}

void BubbleSorting_Increase(KhachHang kh[], int n) {
    for (int i= 0; i < (n - 1); i++) {
        for (int j = (n - 1); j > i; j--) {
            if (kh[j].tongTienThanhToan < kh[j - 1].tongTienThanhToan) {
                KhachHang temp = kh[j];
                kh[j] = kh[j - 1];
                kh[j - 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "o Thong tin khach hang co TONG TIEN cao thu " << i + 1 << ": " << endl;
        cout << " - Ma khach hang: " << kh[i].maKhachHang << endl;
        cout << " - Ten khach hang: " << kh[i].tenKhachHang << endl;
        cout << " - So dien thoai: " << kh[i].soDienThoai << endl;
        cout << " - Tong tien thanh toan: " << kh[i].tongTienThanhToan << endl;
    }
}

int main() {
    int n;
    cout << "=> Nhap so luong khach hang: ";
    cin >> n;
    KhachHang kh[n];

    nhapKhachHang(kh, n);

    cout << "\no Danh sach khach hang vua nhap: " << endl;
    xuatKhachHang(kh, n);

    cout << "\nDanh sach khach hang sau khi sap xep theo tong tien thanh toan tang dan: " << endl;
    BubbleSorting_Increase(kh, n);

    return 0;
}