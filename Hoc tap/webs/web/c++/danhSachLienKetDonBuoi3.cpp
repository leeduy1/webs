#include <iostream>
using namespace std; 

struct node{
	int data;
	struct node *pNext;
};
typedef struct node NODE;

struct list{
	NODE *pHead;
	NODE *PTail;
};
typedef struct list LIST;

void KhoiTaoDSLK(LIST &l) {
	l.pHead = NULL;
    l.PTail = NULL;
	
}

NODE *KhoiTaoNode(int x) {
	NODE *p = new NODE;
	if(p == NULL) {
		cout << "\n ko du bo nho de cap phat ! ";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void ThemVaoDau(LIST &l, NODE *p) {
	if(l.pHead == NULL) {
		l.pHead = l.PTail = p;
	} else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void ThemVaoCuoi(LIST &l, NODE *p) {
	if(l.pHead == NULL) {
		l.pHead = l.PTail = p;
	} else {
		l.PTail->pNext = p;
		l.PTail = p;
	}
} 

void XuatDanhSach(LIST l) {
	for(NODE *k = l.pHead; k != NULL; k = k -> pNext) {
		cout << k->data << " ";
	}
	cout << endl;
}

// them node p vao sau node q(nam trong danh sach lien ket don)
void ThemNode_p_VaoSauNode_q(LIST &l, NODE *p) {
	int x;
	cout << "Nhap gia tri node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x); 
	
	// neu danh sach chi co 1 phan tu do cung chinh la node q ==> bai toan tro thanh ki thuat them vao cuoi
	if(q->data == l.pHead->data && l.pHead->pNext == NULL ) {
		ThemVaoCuoi(l,p);
	} else {
		// duyet tu dau danh sach den cuoi danh sach de tim node q
		for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
			// neu node q co ton tai thi...
			if(q->data == k->data) {
				NODE *h = KhoiTaoNode(p->data);// khoi tao node h moi de them vao sau node q		
				NODE *g = k->pNext; // cho node g tro den node nam sau node q
				h->pNext = g; // buoc1: tao moi lien ket tu node h den node g <=> cung chinh la tao moi lien ket tu node h den node nam sau node q
				k->pNext = h; // buoc2: tao moi lien ket tu node q den node h <=> chinh la node k den node h
			}
		}
	}
}

// them mot not p vao truoc mot node q trong danh sach
void ThemNode_p_VaoTruocNode_q(LIST &l, NODE *p) {
	int x;
	cout << "Nhap gia tri node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x);
	if(q->data = l.pHead->data && l.pHead->pNext == NULL) {
		ThemVaoDau(l,p);
	} else {
//  cach 1: trong danh sach chi ton tai 1 node q;
//		NODE *g = new NODE();
//		for(NODE *k = l.pHead; k!=NULL;k->pNext) {
//			if(q->data == k->data) {
//				// thuc hien bai toan them node p vao sau node g là ra van de <=> them node p vao truoc node q
//				p->pNext = k; // buoc 1: cho node q tro(lien ket) den node k <=> cung chinh la cho node p tro den node q  
//		        g->pNext = p; // buoc 2: cho node g tro den node p
//			}
//			g = k; // giu lien ket voi node nam truoc q trong danh sach
//		}

        NODE *g = new NODE;
		for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
			if(q->data == k->data) {
				// thuc hien bai toan them node p vao sau node g là ra van de <=> them node p vao truoc node q
				NODE *h = KhoiTaoNode(p->data);
				h->pNext = k; // buoc 1: cho node q tro(lien ket) den node k <=> cung chinh la cho node p tro den node q  
		        g->pNext = h; // buoc 2: cho node g tro den node p
			}
			g = k; // giu lien ket voi node nam truoc q trong danh sach
		}
	}
}
 

void Menu(LIST &l) {
	int luachon;
	while(true) {
		cout << "============ MENU ===========" << endl;
		cout << "t1. Them node vao danh sach" << endl;
		cout << "t2. Xuat danh sach lien ket don" << endl;
		cout << "3. Them node p vao sau node q trong danh sach" << endl;
		cout << "4. Them node p vao truoc node q trong danh sach" << endl;
		cout << "t0. Thoat" << endl;
		cout << "============ MENU ===========" << endl;
		
		cout << "Nhap lua chon: ";
		cin >> luachon;
		
		if(luachon < 0 || luachon > 4) {
			cout << "lua chon khong hop le. xin kiem tra lai ! ";
		}
		if(luachon == 1) {
			int x;
			cout << "Nhap gia tri so nguyen: ";
		 	cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemVaoCuoi(l,p);
		} else if(luachon == 2) {
			XuatDanhSach(l);
			system("pause");
		} else if(luachon == 3) {
			int x;
			cout << "Nhap gia tri node p can them vao sau node q: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemNode_p_VaoSauNode_q(l,p);
	    } else if(luachon == 4) {
	    	int x;
			cout << "\nNhap gia tri node p can them vao truoc: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemNode_p_VaoTruocNode_q(l, p);	
		} else {
			break;
		}
	}
}

int main() {
	LIST l;
	KhoiTaoDSLK(l);
	Menu(l);
	system("pause");
	return 0;
	
}

