// Ki thu?t thêm 1 node p vào tru?c node q trong danh sách
#include<iostream>
using namespace std;

int n = 0; // khai bao bien toan cuc - chua toan bo phan tu trong danh sach

// Nh?p danh sách kiên k?t don các s? nguyên
// ============ KHAI BÁO C?U TRÚC DANH SÁCH LIÊN K?T ÐON ============
struct node
{
	int data; // d? li?u c?a 1 node
	struct node *pNext; // con tr? dùng d? liên k?t gi?a các node v?i nhau
};
typedef struct node NODE;

// khai báo c?u trúc danh sách liên k?t don
struct list
{ 
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
// ============ KH?I T?O C?U TRÚC DANH SÁCH LIÊN K?T ÐON ===========
void KhoiTaoDSLK(LIST &l)
{
	// cho 2 node d?u và cu?i tr? d?n vùng nh? r?ng
	l.pHead = NULL;
	l.pTail = NULL;
}

// hàm kh?i t?o 1 cái node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // gán x cho data
	p->pNext = NULL;
	return p;
}


// hàm thêm node p vào d?u danh sách
void ThemVaoDau(LIST &l, NODE *p)
{
	// danh sách dang r?ng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead; // dùng con tr? c?a node p liên k?t v?i l.pHead
		l.pHead = p; // c?p nh?t l?i l.pHead là p
	}
}

// hàm thêm node p vào cu?i danh sách
void ThemVaoCuoi(LIST &l, NODE *p)
{
	// danh sách dang r?ng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p; // c?p nh?t l?i l.pTail là p
	}
}

// xu?t danh sách liên k?t don
void XuatDanhSach(LIST l)
{
	// for(int i = 0; i < n; i++)
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << "  ";
	}
}

// Thêm node p vào sau node q(n?m trong danh sách liên k?t don)
void ThemNode_p_VaoSauNode_q(LIST &l, NODE *p)
{
	int x;
	cout << "\nNhap gia tri node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x);

	// n?u danh sách ch? có 1 ph?n t? và ph?n t? dó cung chính là node q ==> bài toán tr? thành ki thu?t thêm vào cu?i danh sách
	if (q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		ThemVaoCuoi(l, p);
	}
	else
	{
		// duy?t t? d?u danh sách d?n cu?i danh sách d? tìm node q
		for (NODE *k = l.pHead; k != NULL; k = k->pNext)
		{
			// n?u node q có t?n t?i thì....
			if (q->data == k->data)
			{
				NODE *h = KhoiTaoNode(p->data); // kh?i t?o node h m?i d? thêm vào sau node q 
				NODE *g = k->pNext; // cho node g tr? d?n node n?m sau node q
				h->pNext = g; // Bu?c 1: T?o m?i liên k?t t? node h d?n node g <=> cung chính là t?o m?i liên k?t t? node h d?n node n?m sau node q
				k->pNext = h; // Bu?c 2: T?o m?i liên k?t t? node q d?n node h <=> chính là node k d?n node h
			}
		}
	}
}

// Thêm node p vào tru?c node q(n?m trong danh sách liên k?t don)
void ThemNode_p_VaoTruocNode_q(LIST &l, NODE *p)
{
	int x;
	cout << "\nNhap gia tri node q: ";
	cin >> x;
	NODE *q = KhoiTaoNode(x); // kh?i t?o 1 node q

	// n?u danh sách ch? t?n t?i duy nh?t 1 node và node này cung chính là node q luôn - thì v?n d? tr? v? bài toán thêm node p vào d?u danh sách
	if (q->data == l.pHead->data && l.pHead->pNext == NULL)
	{
		ThemVaoDau(l, p); // thêm node p vào d?u danh sách
	} else {
		// ============ CÁCH 1: TRONG DANH SÁCH CH? T?N T?I 1 NODE Q ============
		//NODE *g = new NODE; // node g chính là node gi? liên k?t v?i cái node n?m tru?c node q trong danh sách
		//// duy?t danh sách t? d?u d?n cu?i d? tìm node q
		//for (NODE *k = l.pHead; k != NULL; k = k ->pNext)
		//{
		//	// phát hi?n node q có t?n t?i trong danh sách thì b?t d?u thêm node p vào tru?c node q
		//	if (q->data == k->data)
		//	{
		//		// th?c hi?n bài toán thêm node p vào sau node g là ra v?n d? <=> thêm node p vào tru?c node q
		//		p->pNext = k; // Bu?c 1: cho node p tr?(liên k?t) d?n node k <=> cung chính là cho node p tr? d?n node q
		//		g->pNext = p; // Bu?c 2: cho node g tr? d?n node p 
		//	}
		//	g = k; // gi? liên k?t v?i cái node n?m tru?c node q trong danh sách
		//}

		// ============ CÁCH 2: TRONG DANH SÁCH T?N T?I T? 2 NODE Q TR? LÊN ============
		NODE *g = new NODE; // node g chính là node gi? liên k?t v?i cái node n?m tru?c node q trong danh sách
		// duy?t danh sách t? d?u d?n cu?i d? tìm node q
		for (NODE *k = l.pHead; k != NULL; k = k ->pNext)
		{
			// phát hi?n node q có t?n t?i trong danh sách thì b?t d?u thêm node p vào tru?c node q
			if (q->data == k->data)
			{
				NODE *h = KhoiTaoNode(p->data); // m?i l?n phát hi?n 1 node q thì ta kh?i t?o 1 node p m?i <=> kh?i t?o node h
				// th?c hi?n bài toán thêm node p vào sau node g là ra v?n d? <=> thêm node p vào tru?c node q
				h->pNext = k; // Bu?c 1: cho node h tr?(liên k?t) d?n node k <=> cung chính là cho node h tr? d?n node q
				g->pNext = h; // Bu?c 2: cho node g tr? d?n node h 
			}
			g = k; // gi? liên k?t v?i cái node n?m tru?c node q trong danh sách
		}
		if(q->data == l.pHead->data) {
			ThemVaoDau(l, p);
		}
	}
}

// hàm thêm 1 node p vào 1 v? trí bât kì trong danh sách
void ThemNode_p_VaoViTriBatKi(LIST &l, NODE *p, int vt) { 
    
    // danh sach dang rong
	if(l.pHead == NULL || vt == 1) {
		// them node p vao dau
		ThemVaoDau(l,p);
	} else if(vt == n+1) {
		// them node p vao cuoi
		ThemVaoCuoi(l,p);
	} else {
		int dem = 0; // xac dinh vt can them
		NODE *g = new NODE; // node g chính là node gi? liên k?t v?i cái node n?m tru?c node q trong danh sách
		// duy?t danh sách t? d?u d?n cu?i d? tìm node q <=> tim ra cai vi tri can them node p vao
		for (NODE *k = l.pHead; k != NULL; k = k ->pNext)
		{
			dem++;
			// tim vi tri vt can them
			if (dem == vt)
			{
				NODE *h = KhoiTaoNode(p->data); // m?i l?n phát hi?n 1 node q thì ta kh?i t?o 1 node p m?i <=> kh?i t?o node h
				// th?c hi?n bài toán thêm node p vào sau node g là ra v?n d? <=> thêm node p vào tru?c node q
				h->pNext = k; // Bu?c 1: cho node h tr?(liên k?t) d?n node k <=> cung chính là cho node h tr? d?n node q
				g->pNext = h; // Bu?c 2: cho node g tr? d?n node h 
				break;
			}
			g = k; // gi? liên k?t v?i cái node n?m tru?c node q trong danh sách
		}
	}
}

void XoaDau(LIST &l) {
	if(l.pHead == NULL) {
		return;
	} 
	NODE *p = l.pHead; // Node p la node se xoa
	l.pHead = l.pHead->pNext; // cap nhat lai l.pHead la phan tu ke tiep
	delete p;
}

void XoaCuoi(LIST &l) {
	if(l.pHead == NULL) {
		return;
	}
	// truong hop danh sach co 1 phan tu
	if(l.pHead->pNext == NULL) {
		XoaDau(l);
		return;
	}
	for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
		// phat hien thang ke cuoi
		if(k->pNext == l.pTail) {
			delete l.pTail; 
			k->pNext = NULL;
			l.pTail = k; // cap nhat lai l.ptail
			return;
		}
	}
	
}

// ham xoa 1 node nam sau node q trong danh sach
void XoaSauNODE_q(LIST &l, NODE *q) {
	// duyet danh sach tu dau den den cuoi de tim node q
	for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
		if(k->data == q->data) {
			NODE *g = k->pNext; // node g la nod nam sau node k <=> la node ma ta se xoa
	        k->pNext = g->pNext; // cap nhat moi lien ket
	        delete g; // xoa node nam sau node q
	        return;
		}
	}
}
//void XoaTruocNode_q(LIST &l, NODE *q) {
//	for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
//		
//		if(k->data == q->data) {
//			NODE *g = k->pNext; // node g la nod nam sau node k <=> la node ma ta se xoa
//	        k->pNext = g->pNext; // cap nhat moi lien ket
//	        delete g; // xoa node nam sau node q
//	        return;
//		}
//	}
//}

void XoaTaiViTriBatKi(LIST &l, int vt) {
	if(vt == 1) {
		XoaDau(l);
	} else if(vt == n+1) {
		XoaCuoi(l);
	} else {
		int dem = 1;
		for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
			dem++;
			if(dem == vt) {
				NODE *h = k->pNext;
				k->pNext = h->pNext;
				delete h;
				return;
			}
		}
	}
}

// giai phong vung nho cho danh sach lien ket don
void Giai_Phong_Danh_Sach(LIST &l) {
	NODE *k = NULL;
	while(l.pHead != NULL) {
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		delete k;
	}
}


// menu
void Menu(LIST &l)
{
	int luachon;
	while (69)
	{
		system("cls");
		cout << "\n\n\t\t========== Menu ==========";
		cout << "\n\t1. Them node vao danh sach";
		cout << "\n\t2. Xuat danh sach lien ket don";
		cout << "\n\t3. Them node p vao sau node q trong danh sach";
		cout << "\n\t4. Them node p vao truoc node q trong danh sach";
		cout << "\n\t5. Them node p vao vi tri bat ki trong danh sach";
		cout << "\n\t6. Xoa dau";
		cout << "\n\t7. Xoa cuoi";
		cout << "\n\t8. Xoa node sau node q";
		cout << "\n\t9. Xoa tai mot vi tri bat ki";
		cout << "\n\t0. Thoat";
		cout << "\n\n\t\t========== End ===========";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon < 0 || luachon > 9)
		{
			cout << "\nLua chon khong hop le. Xin kiem tra lai !";
			system("pause"); // d?ng màn hình
		}
		else if (luachon == 1)
		{
			n++;
			int x;
			cout << "\nNhap gia tri so nguyen: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x); // kh?i t?o 1 cái node
			ThemVaoCuoi(l, p); // thêm node vào cu?i danh sách
		}
		else if (luachon == 2)
		{
			XuatDanhSach(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			cout << "\nNhap gia tri node p can them vao sau: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemNode_p_VaoSauNode_q(l, p); // thêm node p vào sau node q trong danh sách l
			n++;
		}
		else if (luachon == 4)
		{
			n++;
			int x;
			cout << "\nNhap gia tri node p can them vao truoc: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			ThemNode_p_VaoTruocNode_q(l, p); // thêm node p vào tru?c node q trong danh sách l
		}
		else if(luachon == 5) {
			// khoi tao gia tri cho node p
			int x;
			cout << "\nNhap gia tri node p: ";
			cin >> x;
			
			NODE *p = KhoiTaoNode(x);
			// nhap vi tri can them cho node p ==> can kiem tra dieu kien
			int vt;
			do {
				cout << "\nNhap vi tri can them node p: ";
				cin >> vt;
				if(vt < 1 || vt > n+1) {
					cout << "\nVitri can them phai nam trong doan[1; " << n+1 << "]";			}
			} while(vt < 1 || vt > n + 1);
			ThemNode_p_VaoViTriBatKi(l,p,vt);
			n++;
		}
		else if(luachon == 6) 
		{
			XoaDau(l);
			n--;
		}
		else if(luachon==7) {
			XoaCuoi(l);
			n--;
		}
		else if(luachon == 8){
			int x;
			cout << "\nNhap node q: ";
			cin >> x;
			NODE *q = KhoiTaoNode(x);
			XoaSauNODE_q(l,q);
			n--;
		} else if(luachon == 9) {
			int x;
			cout << "\nNhap vi tri can xoa;";
			cin >> x;
			XoaTaiViTriBatKi(l,x);
		}
		else
		{
			break; // thoát kh?i vòng l?p hi?n t?i
		}
	}
}

int main()
{
	LIST l;
	KhoiTaoDSLK(l); // luôn luôn g?i hàm kh?i t?o danh sách liên k?t don tru?c khi thao tác v?i danh sách
	Menu(l);

	system("pause");
	return 0;
}
