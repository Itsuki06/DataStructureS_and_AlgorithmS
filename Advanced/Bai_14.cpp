#include <iostream>
#include <string>

using namespace std;

struct date {
    int day;
    int month;
    int year;
};

struct HangHoa {
    int maHangHoa;
    date ngayXuatHang;
    float giaXuatHang;
};

void nhapHangHoa(HangHoa hh[], int n) {
    for (int i = 0; i < n; i++) {
        
        cout << "o Nhap thong tin hang hoa thu " << i + 1 << ": " << endl;
        cout << " - Nhap ma hang hoa: ";
        cin >> hh[i].maHangHoa;

        cout << " - Nhap ngay xuat hang: " << endl;
        cout << "   - Nhap ngay: ";
        cin >> hh[i].ngayXuatHang.day;
        cout << "   - Nhap thang: ";
        cin >> hh[i].ngayXuatHang.month;
        cout << "   - Nhap nam: ";
        cin >> hh[i].ngayXuatHang.year;

        cout << " - Nhap gia xuat hang: " << endl;
        cin >> hh[i].giaXuatHang;
    }
}

void xuatHangHoa(HangHoa hh[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "o Thong tin hang hoa thu " << i + 1 << ": " << endl;
        cout << " - Ma hang hoa: " << hh[i].maHangHoa << endl;
        cout << " - Ngay xuat hang: " << hh[i].ngayXuatHang.day << "/" << hh[i].ngayXuatHang.month << "/" << hh[i].ngayXuatHang.year << endl;
        cout << " - Gia xuat hang: " << hh[i].giaXuatHang << endl;  
    }
}

void insertionSort(HangHoa hh[], int n) {
    for (int i = 1; i < n; i++) {
        int pos = i - 1;
        HangHoa key = hh[i];

        while ((pos >= 0) && (hh[pos].giaXuatHang > key.giaXuatHang)) {
            hh[pos + 1] = hh[pos];
            pos--;
        }

        hh[pos + 1] = key;
    }

    for (int i = 0; i < n; i++) {
        cout << "o Thong tin hang hoa co gia xuat hang xep thu " << i + 1 << ": " << endl;
        cout << " - Ma hang hoa: " << hh[i].maHangHoa << endl;
        cout << " - Ngay xuat hang: " << hh[i].ngayXuatHang.day << "/" << hh[i].ngayXuatHang.month << "/" << hh[i].ngayXuatHang.year << endl;
        cout << " - Gia xuat hang: " << hh[i].giaXuatHang << endl;  
    }
}

void binarySearch(HangHoa hh[], int n, float key) {
    int left = 0;
    int right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (hh[mid].giaXuatHang == key) {
            found = true;
            
            int i = mid;
            while ((i >= 0) && (hh[i].giaXuatHang == key)) {
                cout << "o Thong tin hang hoa " << (i + 1) << ": " << endl;
                cout << " - Ma hang hoa: " << hh[i].maHangHoa << endl;
                cout << " - Ngay xuat hang: " << hh[i].ngayXuatHang.day << "/" << hh[i].ngayXuatHang.month << "/" << hh[i].ngayXuatHang.year << endl;
                cout << " - Gia xuat hang: " << hh[i].giaXuatHang << endl;
                
                i--;
            }

            i = mid + 1;
            while ((i < n) && (hh[i].giaXuatHang == key)) {
                cout << "o Thong tin hang hoa " << (i + 1) << ": " << endl;
                cout << " - Ma hang hoa: " << hh[i].maHangHoa << endl;
                cout << " - Ngay xuat hang: " << hh[i].ngayXuatHang.day << "/" << hh[i].ngayXuatHang.month << "/" << hh[i].ngayXuatHang.year << endl;
                cout << " - Gia xuat hang: " << hh[i].giaXuatHang << endl;
                
                i++;
            }
            break;
        } else if (hh[mid].giaXuatHang < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "o Khong co hang hoa nao co luong bang " << key << endl;
    }
}

int main () {
    int n;
    cout << "=> Nhap so luong hang hoa: ";
    cin >> n;
    
    HangHoa hh[n];

    nhapHangHoa(hh, n);
    xuatHangHoa(hh, n);

    cout << "o Danh sach hang hoa sau khi sap xep: " << endl;
    insertionSort(hh, n);
    
    float key;
    cout << "\n=> Nhap gia xuat xuat hang (KEY) de tim kiem: ";
    cin >> key;

    cout << "\n=> Danh sach hang hoa co gia xuat hang bang " << key << ": " << endl;
    binarySearch(hh, n, key);

    return 0;
}
