#include <iostream>
using namespace std;

struct node {
	int courseID;
	string courseName;
	int number;
	struct node *pNext;
};
typedef struct node NODE;

struct list {
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;

void KhoiTaoDSLK(LIST &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE *KhoiTaoNode(int courseIDE, string courseName, int number) {
	NODE *p = new NODE;
	p->courseID = courseIDE;
	p->courseName = courseName;
	p->number = number;
	p->pNext = NULL;
	return p;
}

void ThemVaoCuoi(LIST &l, NODE *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p; 
	}
}



void XuatDanhSach(LIST l)
{
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout <<"CourseId: "<<k->courseID << "; CourseName: " <<k->courseName<< "; Number of credits: " << k->number <<endl;
	}
}

int main() {
	LIST l;
	KhoiTaoDSLK(l);
	while(true) {
		cout <<"----------MENU----------"<<endl;
		cout<<"1. them mot Node"<<endl;
		cout<<"2. Xoa mot Node khoi danh sach sau nut P" <<endl;
		cout<<"3. In danh sach"<<endl;
		cout<<"----------------------------"<<endl;
		int luachon;
		cout << "Nhap lua chon cua ban: ";
		cin >> luachon;
		if(luachon == 1) {
			int courseID;
			cout << "Nhap CourseID: ";
			cin >> courseID;
			string courseName;
			cout << "Nhap CourseName: ";
			cin >> courseName;
			int number;
			cout << "Nhap number of credits: ";
			cin >> number;
			NODE *p = KhoiTaoNode(courseID,courseName,number);
			ThemVaoCuoi(l,p);
		} else if(luachon == 2) {
			
		
		} else if(luachon == 3) {
			XuatDanhSach(l);
		}
	}
}

 
