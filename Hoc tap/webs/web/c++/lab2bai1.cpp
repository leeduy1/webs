#include <bits/stdc++.h>
using namespace std;

struct node{
	string ten;
	string ngaySinh;
	float diemToan;
	float diemLy;
	float diemNgoaiNgu;
	struct node *pNext;
};
typedef struct node NODE;

struct danhSach
{ 
	NODE *pHead;
	NODE *pTail;
};
typedef struct danhSach LIST;

void KhoiTaoDSLK(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE *KhoiTaoNode(string ten, string ngaySinh, float diemToan, float diemLy, float diemNgoaiNgu)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->ten = ten; 
	p->ngaySinh = ngaySinh;
	p->diemToan = diemToan;
	p->diemLy = diemLy;
	p->diemNgoaiNgu = diemNgoaiNgu;
	p->pNext = NULL;
	return p;
}

void ThemVaoCuoi(LIST &l, NODE *p) {
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	l.pTail->pNext = p;
	l.pTail = p;
}

void XuatDanhSach(LIST l)
{

	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << "Ten sinh vien: " << k->ten << endl;
		cout << "Ngay sinh: " << k->ngaySinh << endl; 
		cout << "Diem toan: " << k->diemToan << endl;
		cout << "Diem ly: " << k->diemLy << endl;
		cout << "Diem ngoai ngu: " << k->diemNgoaiNgu << endl;
	}
}

void XoaDau(LIST &l) {
	if(l.pHead == NULL) {
		return;
	}
	NODE *p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}

void XoaSinhVien(LIST &l, string s) {
	int dem = 0;
	int a = 0;
	for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
		a++;
		if(a == 1) {
			XoaDau(l);
			dem++;
			break;
		}
	}
	NODE *g = new NODE;
	for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
		if(k->ten == s) {
			NODE *p = k;
			g->pNext = k->pNext;
			delete p;
			dem++;
			break;
		}
		g = k;
	}
	
	if(dem == 0) {
		cout << "Khong co ten sinh vien " << s << " trong danh sach" << endl;
	} else {
		cout << "Xoa thanh cong" << endl;
	}
}

float DiemTrungBinh(NODE *p) {
	float a = p->diemToan;
	float b = p->diemLy;
	float c = p->diemNgoaiNgu;
	return (a+b+c)/3; 
}

void ghifile(LIST l) {
	ofstream outfile;
	outfile.open("StudentList.txt", ios::out | ios::trunc);
	for (NODE *k = l.pHead; k != NULL; k = k->pNext) {
		outfile << k->ten << " " << k->ngaySinh << " " << k->diemToan << " " << k->diemLy <<" "<< k->diemToan << endl;
	}
	outfile.close();
	cout << "Ghi file thang cong " << endl;
}


int main(){
	LIST l;
	KhoiTaoDSLK(l);
	string ten;
	string ngaySinh;
	float diemToan;
	float diemLy;
	float diemNgoaiNgu;
	int n;
	while(true) {
		cout << " ========================== MENU ==========================" << endl;
		cout << " 1. Them sinh vien" << endl;
		cout << " 2. In danh sach sinh vien" << endl;
		cout << " 3. Them mot sinh vien moi vao danh sach" << endl;
		cout << " 4. Dem so hoc sinh trong mot nam nhat dinh" << endl;
		cout << " 5. Kiem tra xem co ten sinh vien x trong danh sach hay khong" << endl;
		cout << " 6. Xoa mot hoc sinh khoi danh sach theo ten x" << endl;
		cout << " 7. Tim nhung hoc sinh co diem trung binh lon nhat cua cac mon" << endl;
		cout << " 8. In danh sach hoc sinh co diem mon toan nho hon 5" << endl;
		cout << " 9. Ghi danh sach sinh vien vao tep co ten StudentList.txt" << endl;
		cout << " 10. An phim bat ki de thoat" << endl;
		cout << " ==========================================================" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> n;
		if(n == 1) {
			cout << "Nhap so sinh vien can them vao danh sach: ";
			int x;
			cin >> x;
			for(int i = 0; i < x; i++) {
				cout << "Nhap ten sinh vien: ";
				cin >> ten;
				cout << "Nhap ngay sinh: ";
				cin >> ngaySinh;
				cout << "Nhap diem toan: ";
				cin >> diemToan;
				cout << "Nhap diem ly: ";
				cin >> diemLy;
				cout << "Nhap diem Ngoai ngu: ";
				cin >> diemNgoaiNgu;
				NODE *p = KhoiTaoNode(ten,ngaySinh,diemToan,diemLy,diemNgoaiNgu);
				ThemVaoCuoi(l,p);
			}
		} else if(n == 2) {
			XuatDanhSach(l);
		} else if (n == 3) {
			
		} else if (n == 4) {
			cout << "Nhap nam sinh cua sinh vien can tim kiem: ";
			string s;
			cin >> s;
			for (NODE *k = l.pHead; k != NULL; k = k->pNext) {
				if(k->ngaySinh.find(s) < 1000){		
					cout << "Ten sinh vien: " << k->ten << endl;
					cout << "Ngay sinh: " << k->ngaySinh << endl; 
					cout << "Diem toan: " << k->diemToan << endl;
					cout << "Diem ly: " << k->diemLy << endl;
					cout << "Diem ngoai ngu: " << k->diemNgoaiNgu << endl;
				}
			}
		} else if(n == 5) {
			cout << "Nhap ten sinh vien can kiem tra: ";
			string s;
			cin >> s;
			for (NODE *k = l.pHead; k != NULL; k = k->pNext) {
				if(k->ten == s){		
					cout << "Sinh vien " << s << "co trong danh sach";
				}
			}
		} else if (n == 6) {
			cout << "Nhap ten sinh vien can xoa: ";
			string s;
			cin >> s;
			XoaSinhVien(l,s);
		} else if (n == 7) {
			int max = 0;
			for (NODE *k = l.pHead; k != NULL; k = k->pNext) {
				if(DiemTrungBinh(k) >= max) {
					max = DiemTrungBinh(k);
				}
			}
			for (NODE *k = l.pHead; k != NULL; k = k->pNext) {
				if(DiemTrungBinh(k) == max) {
					cout << "Ten sinh vien: " << k->ten << endl;
					cout << "Ngay sinh: " << k->ngaySinh << endl; 
					cout << "Diem toan: " << k->diemToan << endl;
					cout << "Diem ly: " << k->diemLy << endl;
					cout << "Diem ngoai ngu: " << k->diemNgoaiNgu << endl;
				}
			}
		} else if(n == 8) {
			for (NODE *k = l.pHead; k != NULL; k = k->pNext) {
				if(k->diemToan < 5) { 
					cout << "Ten sinh vien: " << k->ten << endl;
					cout << "Ngay sinh: " << k->ngaySinh << endl; 
					cout << "Diem toan: " << k->diemToan << endl;
					cout << "Diem ly: " << k->diemLy << endl;
					cout << "Diem ngoai ngu: " << k->diemNgoaiNgu << endl;
				}
			}
		} else if (n == 9) {
			ghifile(l);
		} else {
			break;
		}
	}
}
