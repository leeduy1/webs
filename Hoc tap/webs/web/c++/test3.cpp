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

NODE *KhoiTaoNODE(int x) {
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

void DSPTNH(LIST &l1,LIST &l2,int a, int) {
	NODE *h = l1.pHead;
	for(int i = 0; i < a; i++) {
		h = h->pNext;
	}
	for(NODE *k = l1.pHead; k != NULL; k = k->pNext) {
    	if(k->data <= h->data) {
    		NODE *p = KhoiTaoNODE(k->data);
    		ThemVaoCuoi(l2,p);
		}
    }
}

int main() {
	LIST l1,l2;
	KTDSLK(l1);
	KTDSLK(l2);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        NODE *p = KhoiTaoNODE(x);
        ThemVaoCuoi(l1,p);
    }
    int a;
    cin >> a;
    DSPTNH(l1,l2,a,n);
    
    for(NODE *k = l2.pHead; k != NULL; k = k->pNext) {
    	cout << k->data << " ";
    }
}
