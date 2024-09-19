#include <iostream>
#include <string>

using namespace std;

// Định nghĩa lớp Dự án
class DuAn {
private:
    int maDuAn;
    string tenDuAn;
    double tongKinhPhi; // Đơn vị: tỷ đồng

public:
    // Hàm khởi tạo không đối số
    DuAn() : maDuAn(0), tenDuAn(""), tongKinhPhi(0.0) {}

    // Hàm khởi tạo có đối số
    DuAn(int ma, string ten, double kinhPhi) 
        : maDuAn(ma), tenDuAn(ten), tongKinhPhi(kinhPhi) {}

    // Hàm nhập thông tin dự án
    void nhapDuAn() {
        cout << "Nhập mã dự án: ";
        cin >> maDuAn;
        cin.ignore();
        cout << "Nhập tên dự án: ";
        getline(cin, tenDuAn);
        cout << "Nhập tổng kinh phí (tỷ đồng): ";
        cin >> tongKinhPhi;
    }

    // Hàm xuất thông tin dự án
    void xuatDuAn() const {
        cout << "Mã dự án: " << maDuAn 
             << ", Tên dự án: " << tenDuAn 
             << ", Tổng kinh phí: " << tongKinhPhi << " tỷ đồng" << endl;
    }

    // Lấy tổng kinh phí dự án
    double getTongKinhPhi() const {
        return tongKinhPhi;
    }
};

// Hàm nhập vào n dự án
void nhapDanhSachDuAn(DuAn danhSach[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhập thông tin dự án thứ " << i + 1 << ":\n";
        danhSach[i].nhapDuAn();
    }
}

// Hàm xuất ra n dự án
void xuatDanhSachDuAn(const DuAn danhSach[], int n) {
    cout << "\nDanh sách dự án:\n";
    for (int i = 0; i < n; i++) {
        danhSach[i].xuatDuAn();
    }
}

// Hàm sắp xếp bằng Insertion Sort
void insertionSort(DuAn danhSach[], int n) {
    for (int i = 1; i < n; i++) {
        DuAn key = danhSach[i];
        int pos = i - 1;
        while (pos >= 0 && danhSach[pos].getTongKinhPhi() > key.getTongKinhPhi()) {
            danhSach[pos + 1] = danhSach[pos];
            pos--;
        }
        danhSach[pos + 1] = key;
    }
}

// Hàm sắp xếp bằng Bubble Sort
void bubbleSort(DuAn danhSach[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (danhSach[j].getTongKinhPhi() > danhSach[j + 1].getTongKinhPhi()) {
                swap(danhSach[j], danhSach[j + 1]);
            }
        }
    }
}

// Hàm sắp xếp bằng Interchange Sort
void interchangeSort(DuAn danhSach[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (danhSach[i].getTongKinhPhi() > danhSach[j].getTongKinhPhi()) {
                swap(danhSach[i], danhSach[j]);
            }
        }
    }
}

// Hàm sắp xếp bằng Selection Sort
void selectionSort(DuAn danhSach[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (danhSach[j].getTongKinhPhi() < danhSach[minIndex].getTongKinhPhi()) {
                minIndex = j;
            }
        }
        swap(danhSach[i], danhSach[minIndex]);
    }
}

// Hàm chính
int main() {
    int n;
    cout << "Nhập số lượng dự án: ";
    cin >> n;

    DuAn* danhSach = new DuAn[n]; // Khởi tạo mảng dự án động

    nhapDanhSachDuAn(danhSach, n);

    cout << "\n--- Danh sách dự án vừa nhập ---\n";
    xuatDanhSachDuAn(danhSach, n);

    // Sắp xếp danh sách dự án theo tổng kinh phí
    insertionSort(danhSach, n);
    // bubbleSort(danhSach, n); 
    // interchangeSort(danhSach, n); 
    // selectionSort(danhSach, n);
    cout << "\n--- Danh sách dự án sau khi sắp xếp ---\n";
    xuatDanhSachDuAn(danhSach, n);

    delete[] danhSach; // Giải phóng bộ nhớ động

    return 0;
}
