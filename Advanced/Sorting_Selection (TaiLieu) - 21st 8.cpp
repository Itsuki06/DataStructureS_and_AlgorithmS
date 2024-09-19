#include <iostream>
#include <string>

using namespace std;

struct TaiLieu {
    int maTaiLieu;
    string tenTaiLieu;
    int namXuatBan;
    float giaBan;
};

struct Node {
    TaiLieu data;
    Node* next;
    Node* prev;
};

typedef Node* NodePtr;

struct DoubleLinkedList {
    NodePtr head;
    NodePtr tail;
};

TaiLieu input() {
    TaiLieu obj;

    cout << " - Nhap MA TAI LIEU: ";
    cin >> obj.maTaiLieu;

    cout << " - Nhap TEN TAI LIEU: ";
    cin.ignore();
    getline(cin, obj.tenTaiLieu);

    cout << " - Nhap NAM XUAT BAN: ";
    cin >> obj.namXuatBan;

    cout << " - Nhap GIA BAN: ";
    cin >> obj.giaBan;
    
    return obj;
}

void output(NodePtr pnode) {
    cout << " - MA TAI LIEU: " << pnode->data.maTaiLieu << endl;
    cout << " - TEN TAI LIEU: " << pnode->data.tenTaiLieu << endl;
    cout << " - NAM SAN XUAT: " << pnode->data.namXuatBan << endl;
    cout << " - GIA BAN: " << pnode->data.giaBan << endl;
}

int isEmpty(DoubleLinkedList list) {
    return ((list.head == NULL) ? true : false);
}

void initialize(DoubleLinkedList& list) {
    list.head = NULL;
    list.tail = NULL;
}

NodePtr createNode(TaiLieu obj) {
    NodePtr newNode = new Node;

    newNode -> data = obj;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    
    return newNode;
}

void insertTail(DoubleLinkedList& list, TaiLieu obj) {
    NodePtr newNode = createNode(obj);

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
    } else {
        NodePtr current = list.head;
        int i = 0;
        while (current != NULL) {
            cout << "o Thong tin tai lieu: " << ++i << ": " << endl;
            output(current);
            current = current->next;
        }
    }
}

void selectionSort_Increase(DoubleLinkedList& list) {
    if (list.head != NULL) {
        cout << "=> SAP XEP danh sach TANG DAN:" << endl;
        int min;
        for (NodePtr i = list.head; i != list.tail; i = i->next) {
            min = i->data.maTaiLieu;
            for (NodePtr j = i->next; j != NULL; j = j->next) {
                if (min > j->data.maTaiLieu) {
                    min = j->data.maTaiLieu;

                    TaiLieu temp;
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
        NodePtr current = list.head;
        while (current != NULL) {
            cout << "o Thong tin tai lieu co ma " << current->data.maTaiLieu << ": " << endl;
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
    cout << "=> Nhap so luong tai lieu: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "o Nhap thong tin tai lieu " << i + 1 << ": " << endl;
        TaiLieu obj = input();
        insertTail(list, obj); 
    }

    cout << "=> Thong tin " << n << " tai lieu vua nhap: " << endl;
    traverseList(list);

    selectionSort_Increase(list);
    return 0;
}
