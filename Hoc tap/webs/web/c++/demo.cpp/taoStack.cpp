#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *pNext;
};

struct Stack{
	Node *pHead;
};

void CreateStack(Stack &p) {
	p.pHead = NULL;
}

Node *KhoiTaoNode(int x) {
	Node *p = new Node;
	p->data=x;
	p->pNext=NULL;
	return p;
}

// Them vao dau
void Push(Stack &s, Node *p) {
	if(s.pHead == NULL) {
		s.pHead = p;
	} else {
		p->pNext = s.pHead;
		s.pHead = p;
	}
}

// lay phan tu dau ra khoi ngan xep
int Pop(Stack &s) {
	if(s.pHead == NULL) {
		return 0;
	}
	Node *p = s.pHead;
	s.pHead = p->pNext;
	int x = p->data; 
	delete p;
	return x;
}

//lay gia tri phan tu dau ngan xep 

int Top(Stack s) {
	if(s.pHead == NULL) {
		return NULL;
	}
	else {
		return s.pHead->data;
	}
}

int main() {
	Stack s;
	CreateStack(s);
	while(true) {
		cout << "\n====================MENU===================="<<endl;
		cout << "1. Them vao dau" << endl;
		cout << "2. Lay phan tu dau ra khoi ngan xep"<<endl;
		cout << "3. lay gia tri phan tu dau " << endl;
		cout << "4. Xuat stack" << endl;
		cout << "=============================================" << endl;
		int luachon;
		cout << "Nhap lua chon cua ban: ";
		cin >> luachon;
		if(luachon == 1) {
			cout << "Nhap Node: ";
			int x;
			cin >> x;
			Node *p = KhoiTaoNode(x);
			Push(s,p);
		} else if(luachon == 2) {
			cout << Pop(s) << endl;
		} else if(luachon == 3) {
			cout << Top(s);
		} else if(luachon == 4) {
			for(Node *k = s.pHead; k != NULL; k=k->pNext) {
				cout << k->data << " ";
			}
		}
	}
}
