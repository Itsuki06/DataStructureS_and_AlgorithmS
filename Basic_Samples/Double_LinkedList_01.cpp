// Trên ngôn ngữ C/C++, viết chương trình thực hiện yêu cầu sau:
// 1 (1 điểm): Định nghĩa một cấu trúc Sinh viên bao gồm các trường thông tin như sau:
// Mã Sinh viên (kiểu số nguyên), tên Sinh viên (kiểu chuỗi ký tự), lớp (kiểu chuỗi ký tự),
// điểm tổng kết (kiểu số thực), hạnh kiểm (Tốt, khá, trung bình, yếu).
#include <iostream>
#include <string>

using namespace std;

struct SinhVien
{
    string maSV;
    string tenSV;
    string lop;
    int diemTK;
    string hanhKiem;
};

typedef SinhVien TypeOfData;

// 2 (4 điểm): Cài đặt một cấu trúc danh sách liên kết đôi cho kiểu dữ liệu Sinh viên, với
// các thao tác: 1) Khởi tạo danh sách; 

struct Node
{
    SinhVien data;
    Node* next;
    Node* prev;
};

typedef Node *NodePtr;

struct List 
{
    NodePtr head;
    NodePtr tail; 
};

TypeOfData input()
{
    TypeOfData obj;

    cout << " - Ma sinh vien: ";
    cin.ignore();
    getline(cin, obj.maSV);

    cout << " - Ten sinh vien: ";
    getline(cin, obj.tenSV);

    cout << " - Lop: ";
    getline(cin, obj.lop);

    cout << " - Diem tong ket: ";
    cin >> obj.diemTK;

    cout << " - Hanh kiem (Tot, Kha, Trung Binh): ";
    cin.ignore();
    getline(cin, obj.hanhKiem); 

    return obj;
}

void output(NodePtr pnode)
{
    cout << " - Ma sinh vien: " << pnode->data.maSV << endl;
    cout << " - Ten sinh vien: " << pnode->data.tenSV << endl;
    cout << " - Lop: " << pnode->data.lop << endl;
    cout << " - Diem tong ket: " << pnode->data.diemTK << endl;
    cout << " - Hanh kiem: " << pnode->data.hanhKiem << endl;
}

void initialize(List &L)
{
    L.head = NULL;
    L.tail = NULL;
}
int isEmpty(List L)
{
    return ((L.head == NULL && L.tail == NULL) ? true : false);
}
// 2) Tạo mới một nút chứa dữ liệu;
NodePtr createNode(TypeOfData data)
{
    NodePtr newNode = new Node;

    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;

    return newNode;
}
//  3) Chèn nút vào cuối danh sách; 
void insertTail(List &L, TypeOfData data)
{
    NodePtr newNode = createNode(data);

    if (L.head == NULL) {
        L.head = newNode;
        L.tail = newNode;
        return;
    } else {
        L.tail->next = newNode;
        newNode->prev = L.tail;
        L.tail = newNode;    
    }
}
// 4) Tìm kiếm phần tử trong danh sách; 
NodePtr searchOneNode(List L, string maLop)
{
    if (L.head == NULL) {
        return NULL;
    } else {
        NodePtr q;
        q = L.head;
        while (q != NULL) {
            if (q->data.lop.compare(maLop) == 0) {
                break;
            }
            q = q->next;
        }
        return q;
    }
}
//Liệt kê danh sach theo "maLop"
void enumerate(List L, string maLop)
{
    NodePtr p = L.head;
    int i = 0;
    while (p != NULL) {
        if (p->data.lop == maLop) {
            cout << "Thong tin sinh vien " << ++i << " co ma lop \"D13CNPM\": " << endl;
            output(p);
        }
        p = p->next;
    }
    if (i == 0) {
        cout << "Khong co sinh vien nao thuoc lop \"D13CNPM\"!!!" << endl;
    }
}
// 5) Xóa nút cuối cùng khỏi danh sách;
void deleteList(List &L, NodePtr p)
{
    if (p == NULL) {
        cout << "Nut can xoa khong ton tai trong danh sach!!!" << endl;
    }
    else {
        if (L.head == L.tail && p == L.head) {
            L.head = NULL;
            L.tail = NULL;
        }
        else if (p == L.head) {
            L.head = L.head->next;
            L.head->prev = NULL;
            p->next = NULL;
        }
        else if (p == L.tail) {
            L.tail = L.tail->prev;
            L.tail->next = NULL;
            p->prev = NULL;
        }
        else {
            p->prev->next = p->prev;
            p->next->prev = p->next;
            p->prev = NULL;
            p->next = NULL;
        }
        delete p;
    }
}
void deleteTail(List &L)
{
    deleteList(L, L.tail);
}
// 6) Duyệt danh sách.
void traverse(List L)
{
    if (isEmpty(L)) {
        cout << "Danh sach rong!!!" << endl;
    }    
    else {
        NodePtr q;
        q = L.head;
        int i = 0;
        while (q != NULL) {
            // In thong tin phan tu
            cout << "Thong tin sinh vien " << ++i << ": " << endl;
            output(q);
            q = q->next;
        }
    }
}
// 3 (5 điểm): Chương trình chính: Sử dụng cấu trúc danh sách liên kết đơn và các thao
// tác ở trên để:
// - Nhập vào một danh sách liên kết đơn gồm n Sinh viên (n bất kỳ).
// - Hiển thị danh sách đã nhập ra màn hình.
// - Liệt kê ra màn hình danh sách tất cả những Sinh viên thuộc lớp “D13CNPM”.
// - Xóa nút cuối cùng khỏi danh sách. Hiển thị lại danh sách sau khi xóa ra màn hình.
int main() 
{
    List L;
    initialize(L);
    int n;
    cout << "o Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien " << i + 1 << ":" << endl;
        TypeOfData data = input();
        insertTail(L, data);
    }

    cout << "o Danh sach sinh vien vua nhap: " << endl;
    traverse(L);

    cout << "o Danh sach sinh vien co ma lop \"D13CNPM\": " << endl;
    enumerate(L, "D13CNPM");

    cout << "o Danh sach sau khi xoa nut cuoi cung: " << endl;
    deleteTail(L);
    traverse(L); 

    return 0;
}
