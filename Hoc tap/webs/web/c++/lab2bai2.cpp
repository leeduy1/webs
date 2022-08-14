#include <iostream>
using namespace std;

struct node {
	int num;
	int coeff;
	struct node *pNext;
};
typedef struct node NODE;

struct list {
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;

void KTDSLK1(LIST &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

void KTDSLK2(LIST &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

void KTDSLK3(LIST &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE *KhoiTaoNode(int num, int coeff) {
	NODE *p = new NODE;
	if(p == NULL) {
		cout << "Khong du bo nho de cap phat";
		return NULL;
	}
	p->num = num;
	p->coeff = coeff;
	p->pNext = NULL;
	return p;
}

void ThemVaoCuoi(LIST &l, NODE *p) {
	if(l.pTail == NULL) {
		l.pHead = l.pTail = p;
	} else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void InDaThuc(LIST &l) {
	for(NODE *k = l.pHead; k != NULL; k=k->pNext) {
		if(k->num == 1 || k->num == -1 ) {	
			cout << k->num << "x^" <<k->coeff<<" ";
		} else {
			cout << k->num << "x^" <<k->coeff << " + ";
		}
	}
}

void CongHaiDaThuc(LIST &l1, LIST &l2, LIST &l3) {
	for(NODE *k = l1.pHead; k != NULL; k=k->pNext) {
		int dem = 0;
		for(NODE *j = l2.pHead; j != NULL; j=j->pNext) {
			if(k->coeff == j->coeff) {
				int heso = k->num + j->num;
				int somu = k->coeff;
				NODE *p = KhoiTaoNode(heso,somu);
				ThemVaoCuoi(l3,p);
				dem++;	
			}
		}
		if(dem == 0) {
			NODE *p = KhoiTaoNode(k->num,k->coeff);
				ThemVaoCuoi(l3,p);
		}
	}
}
	
void TruHaiDaThuc(LIST &l1, LIST &l2, LIST &l3) {
	for(NODE *k = l1.pHead; k != NULL; k=k->pNext) {
		int dem = 0;
		for(NODE *j = l2.pHead; j != NULL; j=j->pNext) {
			if(k->coeff == j->coeff) {
				int heso = k->num - j->num;
				int somu = k->coeff;
				NODE *p = KhoiTaoNode(heso,somu);
				ThemVaoCuoi(l3,p);
				dem++;	
			}
		}
		if(dem == 0) {
			NODE *p = KhoiTaoNode(k->num,k->coeff);
				ThemVaoCuoi(l3,p);
		}
	}
}

int main() {
	LIST l1;
	KTDSLK1(l1);
	LIST l2;
	KTDSLK2(l2);
	LIST l3;
	KTDSLK3(l3);
	while(true) {
		cout << " ========================== MENU ==========================" << endl;
		cout << " 1. Nhap da thuc " << endl;
		cout << " 2. In ra da thuc " << endl;
		cout << " 3. Thuc hien phep cong hai da thuc " << endl;
		cout << " 4. Thuc hien phep tru hai da thuc " << endl;
		cout << " 5. An phim 5 de thoat" << endl;
		cout << " ==========================================================" << endl;
		int luaChon;
		cout << "Nhap lua chon: " << endl;
		cin >> luaChon;
		if(luaChon < 1 && luaChon >> 5) {
			cout << "Lua chon khong hop le";
		} else if(luaChon == 1) {
//			3x^3 + 2x^2 - x
			int num, coeff;
			while(true) {
				cout << "Nhap he so: ";
				cin >> num;
				cout << "Nhap so mu: ";
				cin >> coeff;
				NODE *p = KhoiTaoNode(num,coeff);
				ThemVaoCuoi(l1,p);
				if(num == -1 || num == 1) {
					break;
				}
			}
			
		} else if (luaChon == 2) {
			InDaThuc(l1);
		} else if (luaChon == 3) {
//			4x3 - x
			cout << "Nhap da thuc can cong: " << endl;
			int num, coeff;
			while(true) {
				cout << "Nhap he so: ";
				cin >> num;
				cout << "Nhap so mu: ";
				cin >> coeff;
				NODE *p = KhoiTaoNode(num,coeff);
				ThemVaoCuoi(l2,p);
				if(num == 1 || num == -1) {
					break;
				}
			}
			CongHaiDaThuc(l1,l2,l3);
			InDaThuc(l3);
		} else if(luaChon == 4) {
			cout << "Nhap da thuc can tru: " << endl;
			int num, coeff;
			while(true) {
				cout << "Nhap he so: ";
				cin >> num;
				cout << "Nhap so mu: ";
				cin >> coeff;
				NODE *p = KhoiTaoNode(num,coeff);
				ThemVaoCuoi(l2,p);
				if(num == 1 || num == -1) {
					break;
				}
			}
			TruHaiDaThuc(l1,l2,l3);
			InDaThuc(l3);
		} else {
			break;
		}
	}
}

