#include <bits/stdc++.h>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct NhanVien {
    int maNhanVien;
    string hoTen;
    Date ngaySinh;
    float luong;
};

void nhapNhanVien(NhanVien nv[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "o Nhap thong tin nhan vien thu " << (i + 1) << ": " << endl;
        cout << " - Ma nhan vien: ";
        cin >> nv[i].maNhanVien;
        
        cin.ignore();
        cout << " - Ho ten nhan vien: ";
        getline(cin, nv[i].hoTen);

        cout << " - Ngay sinh: " << endl;
        cout << " -> Ngay: ";
        cin >> nv[i].ngaySinh.day;
        cout << " -> Thang: ";
        cin >> nv[i].ngaySinh.month;
        cout << " -> Nam: ";
        cin >> nv[i].ngaySinh.year;

        cout << " - Luong: ";
        cin >> nv[i].luong;
    }
}

void xuatNhanVien(NhanVien nv[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "o Thong tin nhan vien " << (i + 1) << ": " << endl;
        cout << " - Ma nhan vien: " << nv[i].maNhanVien << endl;
        cout << " - Ten nhan vien: " << nv[i].hoTen << endl;
        cout << " - Ngay sinh: " << nv[i].ngaySinh.day << "/" << nv[i].ngaySinh.month << "/" << nv[i].ngaySinh.year << endl; 
        cout << " - Luong: " << nv[i].luong << endl;
    }
}

void insertionSort_Increase(NhanVien nv[], int n) {
    for (int i = 1; i < n; i++) {
        int pos = i - 1;
        NhanVien key = nv[i];
        while ((pos >= 0) && (nv[pos].luong > key.luong)) {
            nv[pos + 1] = nv[pos];
            pos--;
        }
        nv[pos + 1] = key; 
    }

    for (int i = 0; i < n; i++) {
        cout << "o Thong tin nhan vien " << i + 1 << ": " << endl;
        cout << " - Ma nhan vien: " << nv[i].maNhanVien << endl;
        cout << " - Ten nhan vien: " << nv[i].hoTen << endl;
        cout << " - Ngay sinh: " << nv[i].ngaySinh.day << "/" << nv[i].ngaySinh.month << "/" << nv[i].ngaySinh.year << endl; 
        cout << " - Luong: " << nv[i].luong << endl;
    }
}

void binarySearch(NhanVien nv[], int n, float key) {
    int left = 0, right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nv[mid].luong == key) {
            found = true;
            // Tim kiem ve ben trai MID (voi cac gia tri nho dan)
            int i = mid;
            while ((i >= 0) && nv[i].luong == key) {
                cout << "o Thong tin nhan vien " << (i + 1) << ": " << endl;
                cout << " - Ma nhan vien: " << nv[i].maNhanVien << endl;
                cout << " - Ten nhan vien: " << nv[i].hoTen << endl;
                cout << " - Ngay sinh: " << nv[i].ngaySinh.day << "/" << nv[i].ngaySinh.month << "/" << nv[i].ngaySinh.year << endl; 
                cout << " - Luong: " << nv[i].luong << endl;
                // Dich chuyen dan ve 0
                i--;                
            }
            // Tim kiem ve ben phai MID (voi cac gia tri lon dan)
            i = mid + 1;
            while ((i < n) && nv[i].luong == key) {
                cout << "o Thong tin nhan vien " << (i + 1) << ": " << endl;
                cout << " - Ma nhan vien: " << nv[i].maNhanVien << endl;
                cout << " - Ten nhan vien: " << nv[i].hoTen << endl;
                cout << " - Ngay sinh: " << nv[i].ngaySinh.day << "/" << nv[i].ngaySinh.month << "/" << nv[i].ngaySinh.year << endl; 
                cout << " - Luong: " << nv[i].luong << endl;
                // Dich chuyen dan ve (n - 1)
                i++;
            }
            break;
        } else if (nv[mid].luong < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "o Khong co nhan vien nao co luong bang " << key << endl;
    }
}

int main() {
    int n;
    cout << "=> Nhap so luong nhan vien: ";
    cin >> n;

    NhanVien nv[n];

    nhapNhanVien(nv, n);
    xuatNhanVien(nv, n);

    cout << "o Danh sach nhan vien sau khi sap xep: " << endl;
    insertionSort_Increase(nv, n);

    float key;
    cout << "\n=> Nhap luong KEY de tim kiem: ";
    cin >> key;

    cout << "\n=> Danh sach nhan vien co luong bang " << key << " la:" << endl;
    binarySearch(nv, n, key);

    return 0;
}