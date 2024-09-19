#include <iostream>
#include <string>

using namespace std;

struct SinhVien {
    int maSinhVien;
    string tenSinhVien;
    string lop;
    float diemTongKet;
};

void nhapSinhVien(SinhVien sv[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "o Nhap thong tin sinh vien " << (i + 1) << ": " << endl;
        
        cout << " - Nhap ma sinh vien: ";
        cin >> sv[i].maSinhVien;

        cin.ignore();
        cout << " - Nhap ten sinh vien: ";
        getline(cin, sv[i].tenSinhVien);

        cout << " - Nhap lop: ";
        getline(cin, sv[i].lop);

        cout << " - Nhap diem tong ket: ";
        cin >> sv[i].diemTongKet; 
    }
}

void xuatSinhVien(SinhVien sv[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "o Thong tin sinh vien thu " << (i + 1) << ": " << endl;

        cout << " - Ma sinh vien: " << sv[i].maSinhVien << endl;
        cout << " - Ten sinh vien: " << sv[i].tenSinhVien << endl;
        cout << " - Lop: " << sv[i].lop << endl;
        cout << " - Diem tong ket: " << sv[i].diemTongKet << endl;
    }
}

void insertionSort(SinhVien sv[], int n) {
    for (int i = 0; i < n; i++) {
        SinhVien key = sv[i];
        int pos = i - 1;
        while ((pos >= 0) && (sv[pos].diemTongKet > key.diemTongKet)) {
            sv[pos + 1] = sv[pos];
            pos--;
        }
        sv[pos + 1] = key;
    }
}

void binarySearch(SinhVien sv[], int n, float key) {
    int left = 0;
    int right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sv[mid].diemTongKet == key) {
            found = true;

            int i = mid;
            while ((i >= 0) && (sv[i].diemTongKet == key)) {
                cout << "o Thong tin sinh vien thu " << (i + 1) << ": " << endl;

                cout << " - Ma sinh vien: " << sv[i].maSinhVien << endl;
                cout << " - Ten sinh vien: " << sv[i].tenSinhVien << endl;
                cout << " - Lop: " << sv[i].lop << endl;
                cout << " - Diem tong ket: " << sv[i].diemTongKet << endl;

                i--;                
            }

            i = mid + 1;
            while ((i < n) && (sv[i].diemTongKet == key)) {
                cout << "o Thong tin sinh vien thu " << (i + 1) << ": " << endl;

                cout << " - Ma sinh vien: " << sv[i].maSinhVien << endl;
                cout << " - Ten sinh vien: " << sv[i].tenSinhVien << endl;
                cout << " - Lop: " << sv[i].lop << endl;
                cout << " - Diem tong ket: " << sv[i].diemTongKet << endl;

                i++;                
            }

            break;
        } else if (sv[mid].diemTongKet < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "o Khong co sinh vien nao co diem tong ket bang " << key << endl;
    }
}

int main() {
    int n;
    cout << "=> Nhap so luong hoc sinh: ";
    cin >> n;

    SinhVien sv[n];

    cout << "=> Nhap thong tin " << n << " sinh vien: " << endl;
    nhapSinhVien(sv, n);

    cout << "=> Danh sach sinh vien vua nhap: " << endl;
    xuatSinhVien(sv, n);

    cout << "=> Sap xep danh sach sinh vien tang dan theo DIEM TONG KET: " << endl;
    insertionSort(sv, n);
    xuatSinhVien(sv, n);

    float key;
    cout << "\n=> Nhap luong KEY de tim kiem: ";
    cin >> key;

    cout << "\n=> Danh sach nhan vien co luong bang " << key << " la:" << endl;
    binarySearch(sv, n, key);

    return 0;
}