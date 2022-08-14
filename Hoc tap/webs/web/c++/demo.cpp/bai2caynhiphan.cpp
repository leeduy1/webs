#include <bits/stdc++.h>
using namespace std;

struct node{
	int data; // du lieu cua node ==> du lieu ma node se luu tru
	struct node *pLeft; // node ben trai cua cay <=> cay con trai
	struct node *pRight; // node ben phai cua cay <=> cay con phai
};
typedef struct node NODE;
typedef NODE* TREE;

// khoi tao cay 
void KhoiTaoCay(TREE &t) {
	t = NULL; // cay rong
}

// ham them phan tu x vao cay nhi phan
void ThemNodeVaoCay(TREE &t, int x) {
	// neu cay rong  
	if(t == NULL) 
	{
		NODE *p = new NODE; //khoi tao 1 cai node de them vao cay
		p->data = x; // them du lieu x vao data;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p; //node p chinh la node goc <=> x
	} 
	else // cay ton tai phan tu 
	{
		// neu phan tu them vao nho hon node goc ==> them no vao ben trai
		if(t->data > x) 
		{
			ThemNodeVaoCay(t->pLeft, x); // duyet qua ben trai de them phan tu x
		}
		else if(t->data < x) 
		{
		    ThemNodeVaoCay(t->pRight, x); // duyet qua ben phai dem them phan tu x
		}
	}
}

// ham xuat cay nhi phan theo NLR
void Duyet_NLR(TREE t) {
	// Neu cay con phan tu thi tiep tuc duyet 
	if(t!=NULL) {
		cout << t->data << " "; // xuat du lieu trong node
		Duyet_NLR(t->pLeft); // duyet qua trai
		Duyet_NLR(t->pRight); // duyet qua phai
	}
}

// ham xuat cay nhi phan theo NRL
void Duyet_NRL(TREE t) {
	if(t!=NULL) {
		cout << t->data << " ";
		Duyet_NRL(t->pRight);
		Duyet_NRL(t->pLeft);
	}
}

// ham xuat cay nhi phan theo LNR <=> xuat ra cac phan tu tu be den lon
void Duyet_LNR(TREE t) {
	if(t!=NULL) {
		Duyet_LNR(t->pLeft);
		cout << t->data << " ";
		Duyet_LNR(t->pRight);
	}
}

// ham xuat cay nhi phan theo RNL <=> xuat ra cac phan tu tu lon den be
void Duyet_RNL(TREE t) {
	if(t!=NULL) {
		Duyet_RNL(t->pRight);
		cout << t->data << " ";
		Duyet_RNL(t->pLeft);
	}
}

// ham xuat cay nhi phan theo LRN
void Duyet_LRN(TREE t) {
	if(t!=NULL) {
		Duyet_LRN(t->pLeft);
		Duyet_LRN(t->pRight);
		cout << t->data << " ";
	}
}

// ham xuat cay nhi phan theo RLN
void Duyet_RLN(TREE t) {
	if(t!=NULL) {
		Duyet_RLN(t->pRight);
		Duyet_RLN(t->pLeft);
		cout << t->data << " ";
	}
}

// ham kiem tra so nguyen to
bool KiemTraSNT(int x) {
	if(x<2) {
		return false;
	}
	for(int i = 2; i <= sqrt(x); i++) {
		if(x % i == 0) {
			return false;
		}
	}
	return true;
}

// ham dem so luong so nguyen to
void SoLuongSoNguyenTo(TREE t, int &dem) {
	if(t!=NULL) {
		// xu li
		if(KiemTraSNT(t->data) == true) {
			dem++;
		}
		
		// 2 cai dong nay co tac dung duyet qua tung cai node trong cay
		SoLuongSoNguyenTo(t->pLeft,dem);
		SoLuongSoNguyenTo(t->pRight,dem);
	}
}

// neu node co ton tai trong cay thi tra ve node do - con khong ton tai thi tra ve null
NODE *TimKiem(TREE t, int x) {
	if(t == NULL) {
		return NULL;
	} else {
		// neu phan tu can tim kiem nho hon node goc thi(dequy)sang trai de tim
		if(x < t->data) {
			TimKiem(t->pLeft, x);
		} else if(x > t->data) {
			TimKiem(t->pRight, x);
		} 
		else // <=> t->data == x
		{
			return t;
		}
	}
}

// Xuat cac node co 2 con
void Node_Co_2_Con(TREE t) {
	if(t != NULL) {
		if(t->pLeft != NULL && t->pRight!=NULL) {
			cout << t->data << " ";
		}
		Node_Co_2_Con(t->pLeft); // duyet sang cay con trai cua node hien tai
		Node_Co_2_Con(t->pRight);	
	}

}

// Xuat cac node co 1 con
void Node_Co_1_Con(TREE t) {
	if(t != NULL) {
		if((t->pLeft != NULL && t->pRight==NULL) || (t->pLeft == NULL && t->pRight!=NULL)) {
			cout << t->data << " ";
		}
		Node_Co_1_Con(t->pLeft); // duyet sang cay con trai cua node hien tai
		Node_Co_1_Con(t->pRight);	
	}

}

// Xuat cac node co 2 con
void Node_La(TREE t) {
	if(t != NULL) {
		if(t->pLeft == NULL && t->pRight==NULL) {
			cout << t->data << " ";
		}
		Node_La(t->pLeft); // duyet sang cay con trai cua node hien tai
		Node_La(t->pRight);	
	}
}

// cach 1
// ham tim phan tu lon nhat trong cay
//int MAX = INT_MIN;
//void TimMax(TREE t) {
//	if(t != NULL) {
//		if(MAX < t->data) {
//			MAX = t->data;
//		}
//		TimMax(t->pLeft);
//		TimMax(t->pRight);
//	}
//}

// cach 2: tim max
int TimMax(TREE t) {
	// neu node cha ma khong khong ton tai cay con trai va cay con phai
	if(t->pLeft==NULL && t->pRight==NULL) {
		return t->data;
	} 
	int max = t->data; // gan gia tribien max la data cua node cha
	// neu node cha co ton tai cay con trai
	if(t->pRight != NULL) {
		int right = TimMax(t->pRight); //left bien se giu gia tri ngoai cung nhat
		if(max < right) {
			max = right;
		}
	}
	return max;	
}

// ham xoa 1 cai node bat ki trong cay nhi phan tim kiem
// data la gia tri node can xoa
void XoaNode(TREE &t, int data) {
	if(t ==NULL) {
		return;
	} else {
		//neu data be hon node goc
		if(data<t->data) {
			XoaNode(t->pLeft,data); // duyet sang nhanh trai cua cay
		} else if(data>t->data) {
			XoaNode(t->pRight,data);
		}
		else { //data == t->data datim ra phan tu can xoa
			NODE *x = t; // node x la node the mang - ti nua chung ta se xoa no
			// neu nhanh trai bang null <=> day la cay con phai
			if(t->pLeft==NULL) {
				t = t->pRight; // duyet sang phai cua cai node can xoa
			} else if(t->pRight==NULL){
				t = t->pLeft; // duyet sang trai cua cai node can xoa de cap nhat moi lien ket giua node cha cua node can xoa voi con cua node can xoa
			}
		}
	}
}


// ham nhap du lieu
void Menu(TREE &t) {
	while(true) {
		cout << "\n =========== MENU =========== ";
		cout << "\n1. Nhap du lieu";
		cout << "\n2. Xuat du lieu cay NLR";
		cout << "\n3. Xuat du lieu cay NRL";
		cout << "\n4. Xuat du lieu cay LNR";
		cout << "\n5. Xuat du lieu cay RNL";
		cout << "\n6. Xuat du lieu cay LRN";
		cout << "\n7. Xuat du lieu cay RLN";
		cout << "\n8. Dem so luong so nguyen to";
		cout << "\n9. Tim kiem node";
		cout << "\n10. Node co 2 con: ";
		cout << "\n11. Node co 1 con: ";
		cout << "\n12. Node la: ";
		cout << "\n13. Node Max : ";	
		cout << "\n0. Ket thuc";
		cout << "\n ============================ ";
		
		int luachon;
		
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if(luachon < 0 || luachon > 14) {
			cout <<"\n Lua chon khong hop le";
		} else if(luachon == 1) {
			int x;
			cout << "\Nhap so nguyen x: ";
			cin >> x;
			ThemNodeVaoCay(t,x);
		} else if(luachon == 2) {
			cout << "\n DUYET CAY THEO NLR\n";
			Duyet_NLR(t);
		}else if(luachon == 3){
			cout << "\n DUYET CAY THEO NRL\n";
			Duyet_NRL(t); 
		} else if(luachon == 4){
			cout << "\n DUYET CAY THEO LNR\n";
			Duyet_LNR(t); 
		} else if(luachon == 5){
			cout << "\n DUYET CAY THEO RNL\n";
			Duyet_RNL(t); 
		} else if(luachon == 6){
			cout << "\n DUYET CAY THEO LRN\n";
			Duyet_LRN(t); 
		} else if(luachon == 7){
			cout << "\n DUYET CAY THEO RLN\n";
			Duyet_RLN(t); 
		} else if(luachon == 8){
			int dem = 0;
			SoLuongSoNguyenTo(t,dem);
			cout << "\n SO LUONG SO NGUYEN TO: " << dem;
		} else if(luachon == 9){
			int x;
			cout << "\n NHAP PHAN TU CAN TIM KIEM:  ";
			cin >> x;
			NODE *p = TimKiem(t,x);
			if(p == NULL) {
				cout << "\nPhan tu " << x << " Khong ton tai trong cay";
			} else {
				cout << "\nPhan tu " << x << " co ton tai trong cay";
			}
			system("pause");
		} else if(luachon == 10){
			cout << "\n\t NODE CO 2 CON: ";
			Node_Co_2_Con(t);
		} else if(luachon == 11){
			cout << "\n\t NODE CO 1 CON: ";
			Node_Co_1_Con(t);
		} else if(luachon == 12){
			cout << "\n\t NODE LA: ";
			Node_La(t);
		} else if(luachon == 13){
			cout << "\n\t NODE Max: ";
			cout << TimMax(t);
		}else {
			break;
		}
	}

}



int main() {
	TREE t;
	KhoiTaoCay(t);
	Menu(t);
	system("pause");
	return 0;
}
