#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *pNext;
};


struct Queue {
	Node *pHead;
	Node *pTail;
};

void Init(Queue &q) {
	q.pHead = NULL;
	q.pTail = NULL;
}

Node *KhoiTaoNode(int x) {
	Node *p = new Node;
	p->pNext=NULL;
	p->data = x;
	return p;
}

// them vao cuoi
void EnQueue(Queue &q, Node *p) {
	if(q.pHead==NULL) {
		q.pHead = q.pTail=p;
	} else {
		q.pTail->pNext=p;
		q.pTail=p;
	}
} 

// lay phan tu dau ra khoi hang doi
int DeQueue(Queue &q) {
	if(q.pHead==NULL) {
		return 0;
	}
	Node *p = q.pHead;
	q.pHead = p->pNext;
	int x = p->data;
	delete p;
	return x;	
}

int Front(Queue q) {
	if(q.pHead==NULL) {
		return 0;
	}
	return q.pHead->data;
}



int main() {
	Queue q;
	Init(q);
	while(true) {
		cout << "\n====================MENU===================="<<endl;
		cout << "1. Them vao cuoi" << endl;
		cout << "2. Lay phan tu ra khoi hang doi"<<endl;
		cout << "3. lay gia tri phan tu dau hang doi" << endl;
		cout << "4. Xuat Queue" << endl;
		cout << "=============================================" << endl;
		int luachon;
		cout << "Nhap lua chon cua ban: ";
		cin >> luachon;
		if(luachon == 1) {
			cout << "Nhap Node: ";
			int x;
			cin >> x;
			Node *p = KhoiTaoNode(x);
			EnQueue(q,p);
		} else if(luachon == 2) {
			cout << DeQueue(q) << endl;
		} else if(luachon == 3) {
			cout << Front(q);
		} else if(luachon == 4) {
			for(Node *k = q.pHead; k != NULL; k=k->pNext) {
				cout << k->data << " ";
			}
		}
	}
}
