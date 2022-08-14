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

void KhoiTaoDSLK(LIST &l) {
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

void ThemVaoDau(LIST &l, NODE *p) {
    if(l.pHead == NULL) {
        l.pHead = l.pTail = p;
    } else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void ThemVaoCuoi(LIST &l, NODE *p) {
    if(l.pHead == NULL) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void ThemVaoViTriBatKi(LIST &l, NODE *p, int vt,int n) {
    if(l.pHead == NULL || vt == 0) {
        ThemVaoDau(l,p);
    } else if(vt == n) {
        ThemVaoCuoi(l,p);
    } else {
        int dem = 0;
        for(NODE *k = l.pHead; k != NULL; k = k -> pNext) {
            dem++;
            if(vt == dem) {
            	NODE *h = KhoiTaoNode(p->data);
            	NODE *g = k->pNext;
            	h->pNext = g;
            	k->pNext = h;
            }
        }
    }
}

int main() {
    LIST l;
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        NODE *p = KhoiTaoNode(x);
        ThemVaoCuoi(l,p);
    }
    int vt;
    cin >> vt;
    int a;
    cin >> a;	
    NODE *h = KhoiTaoNode(a);
    ThemVaoViTriBatKi(l,h,vt,n);
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << " ";
	}
}

