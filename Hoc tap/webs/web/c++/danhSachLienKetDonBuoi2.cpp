#include <iostream>
using namespace std;

// khai bao cau truc node
struct node {
	int data; // du lieu chua 1 cai node
	struct node *pNext; // con tro dung de lien ket giua cac noi vs nhau
};

typedef struct node NODE; // thay the struct node thanh NODE

 // khai bao cau truc cua danh sach lien ket don
 struct list{
 	NODE *pHead; // quan li dau danh sach
 	NODE *pTail; // quan li cuoi danh sach
 };
 
 typedef struct list LIST; // thay struct list thanh LIST
 
 // khoi tao cau truc danh sach lien ket don cac so nguyen
 void KhoiTao(LIST &l) {
 	// cho 2 node tro den NULL - vi danh sach lien ket don chua co phan tu
 	l.pHead = NULL; 
 	l.pTail = NULL;
 }

// khoi tao 1 cai node
NODE *KhoiTaoNODE(int x) {
	NODE *p = new NODE; // cap phat vung` nho cho NODE p
	if(p == NULL) {
		cout << "Khong du bo nho de cap phat";
		return NULL;
	}
	p->data = x; //truyen gia tri x vao cho data
	p->pNext = NULL; // dau tien khai bao node thi node do ch co lien ket nao het ==> con tro cua no se tro den NULL
	return p; // tra ve NODE p vua khoi tao
}

// ham them vao dau danh sach lien ket
void ThemVaoDau(LIST &l, NODE *p) {
	// danh sach dang rong
	if(l.pHead == NULL) {
		l.pHead = l.pTail = p;// node dau cung chinh la node cuoi va la p
	} else {
		p->pNext = l.pHead; // cho con tro cua node can them la node p lien ket den node dau - pHead
		l.pHead = p; // cap nhat lai pHead chinh la node p
	}
}

// ham them node p vao cuoi danh sach lien ket
void ThemVaoCuoi(LIST &l, NODE *p) {
	// danh sach dang rong
	if(l.pHead == NULL) {
		l.pHead = l.pTail = p;// node dau cung chinh la node cuoi va la p
	} else {
		l.pTail->pNext = p; // cho con tro cua pTail lien ket voi node p
		l.pTail = p; // cap nhat lai pTail chinh la node p
	}
}

// ham xuat danh sach lien ket don
void XuatDanhSach(LIST l) {
	for(NODE *k = l.pHead; k != NULL; k = k -> pNext) {
		cout << k->data << " ";
	}
}

int TimMax(LIST l) {
	int max = l.pHead->data;
	for(NODE *k = l.pHead; k != NULL; k = k -> pNext) {
		if(max < k->data) {
			max = k->data;
		}
	}
	return max;
}

int main() {
	LIST l;
	KhoiTao(l);
	int n;
	cout << "Nhap so luong node can them: ";
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int x;
		cout << "\nNhap gia tri so nguyen: ";
		cin >> x;
		NODE *p = KhoiTaoNODE(x); // khoi tao 1 cai node so nguyen
		ThemVaoDau(l,p); // them node p vao dau danh sach lien ket don
	}
	cout << "\n Danh sach lien ket don \n";
	XuatDanhSach(l);
	cout << "\nmax: " << TimMax(l);
	 
	system("pause");
	return 0;
}
