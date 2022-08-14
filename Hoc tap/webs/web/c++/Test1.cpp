#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *pNext;
};
typedef struct node NODE;

struct list{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;

void KTDSLK(LIST &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE *KhoiTaoNode(int x) {
	NODE *p = new NODE;
	if(p == NULL) {
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void ThemVaoCuoi(LIST &l, NODE *p) {
	if(l.pHead == NULL) {
		l.pHead = l.pTail = p;
	} else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

int main() {
	LIST l;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		NODE *p = KhoiTaoNode(x);
		ThemVaoCuoi(l,p);
	}
	int a;
	cin >> a;
	int b; 
	cin >> b;
	int dem = 0;
	for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
		dem++;
		if(dem == a) {
			
		}
	}
	
}
