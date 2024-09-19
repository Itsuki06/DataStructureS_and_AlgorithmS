#include <iostream>
#include <string>

using namespace std;

struct SinhVien {
    int maSinhVien;
    string tenSinhVien;
    string lop;
    float diemTongKet;
};

struct Node {
    SinhVien data;
    Node* next;
    Node* prev;
};

typedef Node* NodePtr;

struct DoubleLinkedList {
    NodePtr head;
    NodePtr tail;
};

SinhVien input() {
    SinhVien obj;

    cout << " - Nhap MA SINH VIEN: ";
    cin >> obj.maSinhVien;

    cout << " - Nhap TEN SINH VIEN: ";
    cin.ignore();
    getline(cin, obj.tenSinhVien);

    cout << " - Nhap LOP: ";
    getline(cin, obj.lop);

    cout << " - Nhap DIEM TONG KET: ";
    cin >> obj.diemTongKet;    

    return obj;
}

void output(NodePtr pnode) {
    cout << " - MA SINH VIEN: " << pnode->data.maSinhVien << endl;
    cout << " - TEN SINH VIEN: " << pnode->data.tenSinhVien << endl;
    cout << " - LOP: " << pnode->data.lop << endl;
    cout << " - DIEM TONG KET: " << pnode->data.diemTongKet << endl;
}

int isEmpty(DoubleLinkedList List) {
    return ((List.head == NULL) ? true : false);
}

void initialize(DoubleLinkedList& list) {
    list.head = NULL;
    list.tail = NULL;
}

NodePtr createNode(SinhVien sv) {
    NodePtr newNode = new Node;

    newNode -> data = sv;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    
    return newNode;
}

void insertTail(DoubleLinkedList& list, SinhVien sv) {
    NodePtr newNode = createNode(sv);

    if (isEmpty(list)) {
        list.head = newNode;
        list.tail = newNode;
    } else {
        list.tail->next = newNode;
        newNode->prev = list.tail;
        list.tail = newNode;
    }
}

void traverseList(DoubleLinkedList list) {
    if (isEmpty(list)) {
        cout << "=> Danh sach rong!!!" << endl;
    } 
    else {
        NodePtr current = list.head;
        int i = 0;
        while (current != NULL) {
            cout << "o Thong tin sinh vien " << ++i << ": " << endl;
            output(current);
            current = current->next;
        }
    }
}

void interChangeSort_Decrease(DoubleLinkedList& list) {
    if (list.head != NULL) {
        cout << "=> SAP XEP danh sach GIAM DAN:" << endl;
        for (NodePtr i = list.head; i != NULL; i = i->next) {
            for (NodePtr j = i->next; j != NULL; j = j->next) {
                if (i->data.diemTongKet < j->data.diemTongKet) {
                    SinhVien temp;
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }    
        }

        NodePtr current = list.head;
        while (current != NULL) {
            cout << "o Thong tin sinh vien co MSV " << current->data.maSinhVien << ": " << endl;
            output(current);
            current = current->next;
        }
    }
    else {
        cout << "=> Danh sach rong!!! Khong the sap xep!!!" << endl;
    }
}

void interChangeSort_Increase(DoubleLinkedList& list) {
    if (list.head != NULL) {
        cout << "=> SAP XEP danh sach TANG DAN:" << endl;
        for (NodePtr i = list.head; i != NULL; i = i->next) {
            for (NodePtr j = i->next; j != NULL; j = j->next) {
                if (i->data.diemTongKet > j->data.diemTongKet) {
                    SinhVien temp;
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }    
        }

        NodePtr current = list.head;
        while (current != NULL) {
            cout << "o Thong tin sinh vien co MSV " << current->data.maSinhVien << ": " << endl;
            output(current);
            current = current->next;
        }
    }
    else {
        cout << "=> Danh sach rong!!! Khong the sap xep!!!" << endl;
    }
}

void selectionSort_Increase(DoubleLinkedList& list) {
    if (list.head != NULL) {
        cout << "=> SAP XEP danh sach TANG DAN:" << endl;
        int min;
        for (NodePtr i = list.head; i != list.tail; i = i->next) {
            min = i->data.maSinhVien;
            for (NodePtr j = i->next; j != NULL; j = j->next) {
                if (min > j->data.maSinhVien) {
                    min = j->data.maSinhVien;

                    SinhVien temp;
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
        NodePtr current = list.head;
        while (current != NULL) {
            cout << "o Thong tin sinh vien co ma " << current->data.maSinhVien << ": " << endl;
                output(current);
                current = current->next;
        }
    }
    else {
        cout << "=> Danh sach rong!!! Khong the sap xep!!!" << endl;
    }
}


int main() {
    DoubleLinkedList list;
    initialize(list);
    
    int n;
    cout << "=> Nhap so luong sinh vien: ";
    cin >> n; 


    for (int i = 0; i < n; i++) {
        cout << "o Nhap thong tin sinh vien " << i + 1 << ": " << endl;
        SinhVien sv = input();
        insertTail(list, sv);
    }

    cout << "=> Thong tin " << n << " sinh vien vua nhap: " << endl;
    traverseList(list);

    interChangeSort_Decrease(list);

    selectionSort_Increase(list);
    return 0;
}