#include <iostream>
#include <string>

using namespace std;

struct VeMayBay {
    int maVe;
    string diemKhoiHanh;
    string diemDen;
    float giaVe;
};

void nhapVe(VeMayBay vmb[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "o Nhap thong tin ve may bay thu " << i + 1 << endl;
        
        cout << " - Nhap ma ve: ";
        cin >> vmb[i].maVe;
        
        cin.ignore();
        cout << " - Nhap diem khoi hanh: ";
        getline(cin, vmb[i].diemKhoiHanh);

        cout << " - Nhap diem den: ";
        getline(cin, vmb[i].diemDen);

        cout << " - Nhap gia ve: ";
        cin >> vmb[i].giaVe;
    }
}

void xuatVe(VeMayBay vmb[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "o Thong tin ve may bay thu " << i + 1 << ": " << endl;
        
        cout << " - Ma ve: " << vmb[i].maVe << endl;
        cout << " - Diem Khoi hanh: " << vmb[i].diemKhoiHanh << endl;
        cout << " - Diem den: " << vmb[i].diemDen << endl;
        cout << " - Gia ve: " << vmb[i].giaVe << endl;
    }
}

void bubbleSort(VeMayBay vmb[], int n) {
    for (int i = 0; i < (n - 1); i++) {
        for (int j = (n -1); j > i; j--) {
            if (vmb[j].giaVe < vmb[j - 1].giaVe) {
                VeMayBay temp = vmb[j];
                vmb[j] = vmb[j - 1];
                vmb[j - 1] = temp;
            }
        }
    }
}

void binarySearch(VeMayBay vmb[], int n, float key) {
    int left = 0;
    int right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vmb[mid].giaVe == key) {
            int i = mid;
            while ((i >= 0) && (vmb[i].giaVe == key)) {
                cout << "o Thong tin ve may bay thu " << i + 1 << ": " << endl;
                cout << " - Ma ve: " << vmb[i].maVe << endl;
                cout << " - Diem Khoi hanh: " << vmb[i].diemKhoiHanh << endl;
                cout << " - Diem den: " << vmb[i].diemDen << endl;
                cout << " - Gia ve: " << vmb[i].giaVe << endl;
                i--;
            }

            i = mid + 1;
            while ((i < n) && (vmb[i].giaVe == key)) {
                cout << "o Thong tin ve may bay thu " << i + 1 << ": " << endl;
                cout << " - Ma ve: " << vmb[i].maVe << endl;
                cout << " - Diem Khoi hanh: " << vmb[i].diemKhoiHanh << endl;
                cout << " - Diem den: " << vmb[i].diemDen << endl;
                cout << " - Gia ve: " << vmb[i].giaVe << endl;
                i++;
            }
            break;
        } else if (vmb[mid].giaVe > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (!found) {
        cout << "o Khong co ve may bay nao co gia " << key << endl;
    }
}

int main() {
    int n;
    cout << "=> Nhap so luong ve may bay: ";
    cin >> n;

    VeMayBay vmb[n];

    cout << "=> Nhap thong tin " << n << " ve may bay: " << endl;
    nhapVe(vmb, n);

    cout << "=> Thong tin " << n << " ve may bay vua nhap: " << endl;
    xuatVe(vmb, n);

    cout << "=> Danh sach ve may bay sau khi sap xep tang dan: " << endl;
    bubbleSort(vmb, n);
    xuatVe(vmb, n);

    float key;
    cout << "=> Nhap gia ve (KEY) de tim ve may bay: ";
    cin >> key;

    cout << "=> Danh sach ve may bay co gia bang " << key << ": " << endl;
    binarySearch(vmb, n, key);

    return 0;
}