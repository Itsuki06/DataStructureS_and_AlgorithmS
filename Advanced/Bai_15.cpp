// Bài 15:
// Sinh viên hãy lập trình giải bài toán quản lý khách hàng, trong chương trình thực hiện các công
// việc sau:
// Câu 1. (2 -) Định nghĩa một cấu trúc Khách hàng, bao gồm các trường thông tin như sau: Mã
// khách hàng (kiểu số nguyên), tên khách hàng (kiểu chuỗi ký tự), số điện thoại (kiểu chuỗi
// ký tự), tổng tiền thanh toán (kiểu số).

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct KhachHang {
    int maKhachHang;
    string tenKhachHang;
    string soDienThoai;
    float tongTien;
};
// Câu 2. (2 -) Viết hàm nhập vào một mảng gồm n khách hàng
void nhapKhachHang(vector<KhachHang>& danhSach, int n) {
    for (int i = 0; i < n; i++) {
        KhachHang obj;
        cout << "o Nhap thong tin khach hang thu " << i + 1 << ":\n";
        cout << " - Ma khach hang: ";
        cin >> obj.maKhachHang;
        cin.ignore();
        cout << " - Ten khach hang: ";
        getline(cin, obj.tenKhachHang);
        cout << " - So dien thoai: ";
        getline(cin, obj.soDienThoai);
        cout << " - Tong tien thanh toan: ";
        cin >> obj.tongTien;
        danhSach.push_back(obj);
    }
}
// Câu 3. (1 -) Viết hàm xuất ra mảng n khách hàng vừa nhập.
void xuatKhachHang(vector<KhachHang>& danhSach) {
    cout << "\nDanh sach khach hang vua nhap: " << endl;
    for (const auto& obj : danhSach) {
        cout << " - Ma khach hang: " << obj.maKhachHang << endl;
        cout << " - Ten khach hang: " << obj.tenKhachHang << endl;
        cout << " - So dien thoai: " << obj.soDienThoai << endl;
        cout << " - Tong tien thanh toan: " << obj.tongTien << endl;
    }
}
// Câu 4. (2 -) Sử dụng phương pháp sắp xếp chèn trực tiếp(quick sort), viết hàm sắp xếp các
// khách hàng theo chiều tăng dần của tổng tiền thanh toán
int partition (vector<KhachHang>& danhSach, int low, int high) {
    float pivot = danhSach[high].tongTien; //Phan tu chot;
    int i = low - 1;  //Chi so cua phan tu nho hon;

    for (int j = low; j <= high - 1; j++) {
        if (danhSach[j].tongTien < pivot) {
            i++;
            swap(danhSach[i], danhSach[j]);
        }
    }
    swap(danhSach[i + 1], danhSach[high]);
    return (i + 1);
}

void quickSort(vector<KhachHang>& danhSach, int low, int high) {
    if (low < high) {
        int pi = partition(danhSach, low, high);
        quickSort(danhSach, low, pi - 1);
        quickSort(danhSach, pi + 1, high);
    }
}
// Câu 5. (1.5 -). Áp dụng chiến lược chia để trị (bằng thuật toán tìm kiếm nhị phân). Viết hàm tìm
// kiếm các khách hàng có tổng tiền thanh toán bằng X.
void binarySearch(const vector<KhachHang>& danhSach, float key) {
    int low = 0;
    int high = danhSach.size() - 1;
    bool found = false;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (danhSach[mid].tongTien == key) {
            cout << "o Tim thay khach hang: \n";
            cout << " - Ma khach hang: " << danhSach[mid].maKhachHang << endl;
            cout << " - Ten khach hang: " << danhSach[mid].tenKhachHang << endl;
            cout << " - So dien thoai: " << danhSach[mid].soDienThoai << endl;
            cout << " - Tong tien thanh toan: " << danhSach[mid].tongTien << endl;
            found = true;
            break;
        }

        if (danhSach[mid].tongTien < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "Not FOUND! " << key << endl;
    }
}
// Câu 6. (1.5 -). Viết hàm chính thực hiện:
// - (0.5 -) Nhập vào n khách hàng và hiển thị các khách hàng vừa nhập
// - (0.5 -) Sắp xếp n khách hàng theo chiều tăng dần của tổng tiền thanh toán.

// - (0.5 -) Sử dụng hàm tìm kiếm hiển thị các khách hàng có tổng tiền thanh toán bằng X (X
// do người dùng nhập vào)
// Hàm chính
int main() {
    int n;
    cout << "Nhap so luong khach hang: ";
    cin >> n;

    vector<KhachHang> danhSach;
    nhapKhachHang(danhSach, n);

    cout << "\n--- Danh sach khach hang ---\n";
    xuatKhachHang(danhSach);

    // Sắp xếp danh sách vé máy bay theo giá tăng dần
    quickSort(danhSach, 0, danhSach.size() - 1);
    cout << "\n--- Danh sach khach hang sau khi sap xep ---\n";
    xuatKhachHang(danhSach);

    // Tìm kiếm vé máy bay theo giá vé
    float key;
    cout << "\n=> Nhap tong tien can tim: ";
    cin >> key;
    binarySearch(danhSach, key);

    return 0;
}