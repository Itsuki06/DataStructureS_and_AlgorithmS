#include<iostream>
#include<string>

using namespace std;

struct PhanSo
{
	int tuSo;
	int mauSo;
};

///// Nhập dữ liệu cho PhanSo
PhanSo nhapPhanSo()
{
	PhanSo ps;

	cout << " - Tu so: ";
	cin >> ps.tuSo;

	cout << " - Mau so: ";
	int mauSo;
	do
	{
		cin >> mauSo;
		if (mauSo == 0) cout << " - Nhap lai mau so (khac KHONG): ";
	}
	while (mauSo == 0);
	ps.mauSo = mauSo;

	return ps;
}

///// In phân số
void inPhanSo(PhanSo ps)
{
	cout << ps.tuSo << "/" << ps.mauSo << endl;
}

struct Node
{
	PhanSo ps;
	struct Node *next;
};

typedef Node *NodePtr;

///// In thông tin của một nút
void inNode(NodePtr pnode)
{
	inPhanSo(pnode->ps);
}

///// Tạo một nút
NodePtr createNode(PhanSo ps) {
	NodePtr p = new Node;

	p->next = NULL;
	p->ps = ps;

	return p;
}

struct Stack
{
	NodePtr Head;
	NodePtr Tail;
	int size;
};

///// Khởi tạo
void initStack(Stack &s)
{
	s.Head = NULL;
	s.Tail = NULL;
	s.size = 0;
}

///// Kiểm tra rỗng
bool isStackEmpty(Stack s)
{
	return s.size == 0;
}

///// Thêm vào ngăn xếp một phần tử x
void push(Stack &s, PhanSo x) {
	NodePtr p = createNode(x);

	if (isStackEmpty(s))
	{
		s.Head = p;
		s.Tail = p;
	}
	else
	{
		p->next = s.Head;
		s.Head = p;
	}
    
	s.size++;
}

///// Lấy một phần tử từ ngăn xếp
void pop(Stack &s, PhanSo &x)
{
	if (isStackEmpty(s))
		cout << "Ngan xep rong!" << endl;
	else
	{
		NodePtr p = s.Head;
		x = p->ps;
        s.Head = s.Head->next;
		s.size--;
		delete p;
	}
}

///// Trả về số lượng phần tử trong ngăn xếp
int sizeOfStack(Stack s)
{
	return s.size;
}

///// Hiển thị các phân số có trong ngăn xếp và tính tổng
///// Hàm này lấy các phân số trong ngăn xếp, in ra màn hình và tính tổng
void hienThiVaTinhTong(Stack s)
{
	float sum = 0;
	int i = 1;
	while (!isStackEmpty(s))
	{
		PhanSo ps;
		pop(s, ps);
		
		cout << "Phan so " << i << ": ";
		inPhanSo(ps);
		
		sum += (float)ps.tuSo / ps.mauSo;
		
		i++;
	}
	cout << "Tong cac phan so la: " << sum << endl;
}

int main()
{
	Stack s;
	
	initStack(s);
	
	///// Cau 3:
	cout << "===== NHAP DANH SACH PHAN SO VAO NGAN XEP =====" << endl;
	int n;
	cout << "Nhap so luong phan so: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan so " << i + 1 << ":" << endl;
		PhanSo ps = nhapPhanSo();
		push(s, ps);
	}
	
	cout << "===== DANH SACH CAC PHAN SO CO TRONG NGAN XEP VA TONG CUA CHUNG =====" << endl;
	hienThiVaTinhTong(s);
	//hienThiVaTinhTong2(s);
}
