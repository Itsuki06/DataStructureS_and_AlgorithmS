// Trên ngôn ngữ C/C++, viết chương trình thực hiện yêu cầu sau:
// 1 (1 điểm): Định nghĩa một cấu trúc Học viên bao gồm các trường thông tin như sau:
// Mã học viên (kiểu số nguyên), tên học viên (kiểu chuỗi ký tự), lớp (kiểu chuỗi ký tự),
// chuyên ngành (Khoa học máy tính, Thương mại điện tử, Quản trị an ninh mạng), điểm
// tổng kết (kiểu số thực).
#include <iostream>
#include <string>

using namespace std;

struct HocVien {
    int maHV;
    string tenHV;
    string lop;
    string chuyenNganh;
    float diemTongKet;    
};

struct Node {
    HocVien data;
    Node *next;
    Node *prev;
};

typedef Node* NodePtr;

struct List {
    NodePtr head;
    NodePtr tail;
};

HocVien input() {
    HocVien obj;

    cout << " - Nhap MA HOC VIEN: ";
    cin >> obj.maHV;

    cout << " - Nhap TEN HOC VIEN: ";
    cin.ignore();
    getline(cin, obj.tenHV);

    cout << " - Nhap LOP: ";
    getline(cin, obj.lop);

    cout << " - Nhap CHUYEN NGANH: ";
    getline(cin, obj.chuyenNganh);

    cout << " - Nhap DIEM TONG KET: ";
    cin >> obj.diemTongKet;    

    return obj;
}

void output(NodePtr pnode) {
    cout << " - MA HOC VIEN: " << pnode->data.maHV << endl;
    cout << " - TEN HOC VIEN: " << pnode->data.tenHV << endl;
    cout << " - LOP: " << pnode->data.lop << endl;
    cout << " - CHUYEN NGANH: " << pnode->data.chuyenNganh << endl;
    cout << " - DIEM TONG KET: " << pnode->data.diemTongKet << endl;
}
int isEmpty(List L) {
    return ((L.head == NULL && L.tail == NULL) ? true : false);
}
// 2 (4 điểm): Cài đặt một cấu trúc danh sách liên kết đôi cho kiểu dữ liệu Học viên, với
// các thao tác: 1) Khởi tạo danh sách; 
void initialize(List &L) {
    L.head = NULL;
    L.tail = NULL;
}
// 2) Tạo mới một nút chứa dữ liệu; 
NodePtr createNode(HocVien data) {
    NodePtr newNode = new Node;

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}
// 3) Chèn nút vào cuối danh sách; 
void insertTail(List &L, HocVien data) {
    NodePtr newNode = createNode(data);

    if (isEmpty(L)) {
        L.head = newNode;
        L.tail = newNode;
        return;
    }
    L.tail->next = newNode;
    newNode->prev = L.tail;
    L.tail = newNode;
}
// 4) Tìm kiếm phần tử trong danh sách; 
void searchByMajor(List L, string nganh, float diem) {
    int i = 0;
    if (isEmpty(L)) {
        cout << "=> Danh sach rong!!!" << endl;
    }
    else {
        NodePtr q = L.head;
        while (q != NULL) {
            if ((q->data.chuyenNganh.compare(nganh) == 0) && (q->data.diemTongKet >= diem)) {
                cout << "Hoc vien " << ++i  << ": " << endl;
                output(q);
            }
            q = q->next;
        }
    }
    
    if (i == 0) {
        cout << "=> Khong co hoc vien nao co nganh la \"" << nganh << "\" trong danh sach!!!";
    }
}
// 5) Duyệt danh sách.
void traverse(List L) {
    if (isEmpty(L)) {
        cout << "=> Danh sach rong!!!" << endl;
    }
    else {
        NodePtr q = L.head;
        int i = 0;
        while (q != NULL) {
            cout << "Thong tin hoc vien " << ++i << ": " << endl;
            output(q);
            q = q->next;
        }
    }
}
//6) Sort
void sortList(List &L) {
    if (L.head != NULL) {
            for (NodePtr i = L.head; i != NULL; i = i->next) {
                for (NodePtr j = i->next; j != NULL; j = j->next) {
                    if (i->data.tenHV.compare(j->data.tenHV) > 0) {
                        string temp;
                        temp = i->data.tenHV;
                        i->data.tenHV = j->data.tenHV;
                        j->data.tenHV = temp;
                    }
                }
            }
    }    
    else {
        cout << "o Danh sach rong!!! Khong the sap xep!!!" << endl;
    }
}
// 3 (5 điểm): Chương trình chính: Sử dụng cấu trúc danh sách liên kết đôi và các thao tác
// đã tạo để:
int main() {
// - Nhập và 1 danh sách gồm n Học viên (n bất kỳ).
    List L;
    initialize(L);

    int n;
    cout << "o Nhap so hoc vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "o Nhap thong tin hoc vien " << i + 1 << ": " << endl;
        HocVien hv = input();
        insertTail(L, hv);
    }
// - Hiển thị danh sách đã nhập ra màn hình.
    cout << "o Thong tin " << n << " sinh vien vua nhap: " << endl;
    traverse(L);
// - Liệt kê ra màn hình danh sách tất cả những Học viên thuộc chuyên ngành “Thương
// mại điện tử” và có điểm tổng kết ≥ 8.0.
    string nganh;
    float diem;
    cout << "o Nhap CHUYEN NGANH muon tim: ";
    cin.ignore();
    getline(cin, nganh);
    cout << "o Nhap DIEM TONG KET muon tim: ";
    cin >> diem;
    cout << "o Hoc vien" << " co chuyen nganh \"" << nganh << "\" va co diem tong ket >= " << diem << ": " << endl;
    searchByMajor(L, nganh, diem);
// - Sắp xếp danh sách đã nhập theo tên học viên (thứ tự alphabet), hiện thị danh sách
// đã sắp ra màn hình.
    sortList(L);
    traverse(L);
    return 0;
}
