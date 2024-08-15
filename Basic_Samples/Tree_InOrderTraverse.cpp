// Bài 48
// Trên ngôn ngữ C/C++, viết chương trình thực hiện yêu cầu sau:
// 1: Định nghĩa một cấu trúc Môn học gồm các thông tin: Mã môn học, tên môn học, số
// tín chỉ, số tiết đã giảng dạy.
#include <iostream>
#include <string>

using namespace std;

struct MonHoc
{
    int maMH;
    string tenMH;
    int soTC;
    int soTietDay;
};
// 2: Cài đặt một cấu trúc cây nhị phân tìm kiếm cho kiểu dữ liệu Môn học với mã môn
// học làm trường Khóa, với các thao tác:
struct TypeOfNode 
{
    MonHoc data;
    TypeOfNode *left;
    TypeOfNode *right;
};

typedef TypeOfNode *NodePtr;
typedef TypeOfNode *Tree;

MonHoc input()
{
    MonHoc data;
    cout << "- Nhap MA MON HOC (1 so nguyen): ";
    cin >> data.maMH;

    cout << " - Nhap TEN MON HOC: ";
    cin.ignore();
    getline(cin, data.tenMH);

    cout << " - Nhap SO TIN CHI: ";
    cin >> data.soTC;

    cout << " - Nhap SO TIET DAY: ";
    cin >> data.soTietDay;

    return data;
}

void output(NodePtr pnode)
{
    cout << " - MA MON HOC: " << pnode->data.maMH << endl;
    cout << " - TEN MON HOC: " << pnode->data.tenMH << endl;
    cout << " - SO TIN CHI: " << pnode->data.soTC << endl;
    cout << " - SO TIET DAY: " << pnode->data.soTietDay << endl;
}
// 1) Khởi tạo cây; 
void initialize(Tree &T) 
{
    T = NULL;
}
// 2) Tạo mới một nút chứa dữ liệu; 
NodePtr createNode(MonHoc data)
{
    NodePtr newNode = new TypeOfNode;
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
// 3) Chèn nút vào cây;
void insertNode(Tree &T, MonHoc data)
{
    NodePtr p = createNode(data);

    if (T == NULL) {
        T = p;
    }
    else if (data.maMH < T->data.maMH) {
        insertNode(T->left, data);
    }
    else if (data.maMH > T->data.maMH) {
        insertNode(T->right, data);
    }
} 
// 4) Tìm kiếm phần tử trong cây; 
NodePtr search(Tree T, int maMH)
{
    if (T != NULL) {
        if (maMH < T->data.maMH) {
            return search(T->left, maMH);
        }
        else if (maMH > T->data.maMH) {
            return search(T->right, maMH);
        }
        else {
            return T;
        }
    }
    else {
        return NULL;
    }
}
// 5) Duyệt cây.
void inOrder(Tree T)
{
    if (T != NULL) {
        inOrder(T->left);
        cout << "=========================" << endl;
        output(T);
        inOrder(T->right);
    }
}
// 6) Liệt kê.
void enumerate(Tree T, int &t)
{
    if (T != NULL) {
        enumerate(T->left, t);
        if (T->data.soTietDay >= 30) {
            if (t == 0) {
                cout << "==> Cac mon hoc co SO TIET DAY >= 30: " << endl;
            }
            cout << "=========================" << endl;
            output(T);
            t = t + 1;
        }
        enumerate(T->right, t);
    }
}
// 3: Trong chương trình chính nhập vào một cây nhị phân tìm kiếm gồm n môn học (n
// bất kỳ).
int main()
{
    int n;
    do {
        cout << "o Nhap SO MON HOC: ";
        cin >> n;
    } while (n <= 0);

    Tree T;
    initialize(T);

    for (int i = 0; i < n; i++) {
        cout << "o Nhap thong tin mon hoc thu " << i + 1 << ": " << endl;
        MonHoc data = input();
        insertNode(T, data);
    }
// 4: Trong chương trình chính sử dụng hàm Duyệt cây liệt kê ra màn hình danh sách tất
// cả môn học có trong cây.
    cout << "o Cac mon hoc vua nhap: " << endl;
    inOrder(T);
// 5: Trong chương trình chính, nhập vào một mã môn học, sử dụng hàm Tìm kiếm phần
// tử trong cây, hiển thị thông tin môn học có mã môn học vừa nhập, nếu không có trong
// cây nhị phân đưa ra thông báo không có môn học trong cây.
    int id;
    cout << "o Nhap MA MON HOC can tim: ";
    cin >> id;

    NodePtr p = search(T, id);

    if (p) {
        cout << "==> Thong tin mon hoc co MA " << id << " la: " << endl;
        output(p);
    }
    else {
        cout << "==> Khong co MON HOC CAN TIM trong cay!!!" << endl;
    }
// 6: Liệt kê tất cả các môn học có số tiết đã giảng dạy lớn hơn 30.
    int t = 0;
    enumerate(T, t);
    if (t == 0) {
        if (T != NULL) {
            cout << "==> Khong co mon hoc nao co SO TIET DAY >= 30!!!" << endl;
        }   
        else {
            cout << "==> Danh sach rong!!" << endl;
        }     
    }

    return 0;
}

