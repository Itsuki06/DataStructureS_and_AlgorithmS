#include <iostream>
#include <string>

using namespace std;

struct MonHoc {
    string maMonHoc;
    string tenMonHoc;
    int soTinChi;
    int soTietDaDay;
};

struct Node {
    MonHoc data;
    Node* next;
    Node* prev;
};

typedef Node* NodePtr;

struct DoubleLinkedList {
    NodePtr head;
    NodePtr tail;
};

MonHoc input() {
    MonHoc obj;

    cout << " - Nhap MA MON HOC: ";
    cin.ignore();
    getline(cin, obj.maMonHoc);

    cout << " - Nhap TEN MON HOC: ";
    getline(cin, obj.tenMonHoc);

    cout << " - Nhap SO TIN CHI: ";
    cin >> obj.soTinChi;

    cout << " - Nhap SO TIET DA DAY: ";
    cin >> obj.soTietDaDay;

    return obj;
}

void output(NodePtr pnode) {
    cout << " - MA MON HOC: " << pnode->data.maMonHoc << endl;
    cout << " - TEN MON HOC: " << pnode->data.tenMonHoc << endl;
    cout << " - SO TIN CHI: " << pnode->data.soTinChi << endl;
    cout << " - SO TIET DA DAY: " << pnode->data.soTietDaDay << endl;
}

int isEmpty(DoubleLinkedList list) {
    return ((list.head == NULL) ? true : false);
}

void initialize(DoubleLinkedList& list) {
    list.head = NULL;
    list.tail = NULL;
}

NodePtr createNode(MonHoc obj) {
    NodePtr newNode = new Node;

    newNode->data = obj;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void insertTail(DoubleLinkedList& list, MonHoc obj) {
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

void traverse(DoubleLinkedList list) {
    if (isEmpty(list)) {
        cout << "=> Danh sach rong!" << endl;
    } else {
        NodePtr current = list.head;
        int i = 0;
        while (current != NULL) {
            cout << "o Thong tin mon hoc " << ++i << ": " << endl;
            output(current);
            current = current->next;
        }
    }
}


void insertionSort_Increase(DoubleLinkedList& list) {
    if (isEmpty(list)) {
        cout << "=> Danh sach rong! Khong the sap xep!" << endl;
        return;
    }
    
    for (NodePtr i = list.head->next; i != NULL; i = i->next) {
        MonHoc key = i->data;
        NodePtr j = i->prev;
        
        // Di chuyển các phần tử có soTietDaDay lớn hơn key về sau
        while (j != NULL && j->data.soTietDaDay > key.soTietDaDay) {
            j->next->data = j->data;
            j = j->prev;
        }
        
        // Đặt key vào vị trí đúng
        if (j == NULL) {
            list.head->data = key;
        } else {
            j->next->data = key;
        }
    }
    
    cout << "=> Danh sach sau khi sap xep TANG DAN theo SO TIET DA DAY: " << endl;
    traverse(list);
}

int main() {
    DoubleLinkedList list;
    initialize(list);

    int n;
    cout << "=> Nhap so mon hoc: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "=> Nhap thong tin mon hoc " << i + 1 << ": " << endl;
        MonHoc obj = input();
        insertTail(list, obj);
    }

    cout << "=> Thong tin cac mon hoc vua nhap: " << endl;
    traverse(list);

    insertionSort_Increase(list);

    return 0;
}
