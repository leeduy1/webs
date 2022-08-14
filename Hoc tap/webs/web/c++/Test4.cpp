#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *pNext;
};
typedef struct node NODE;

struct list
{ 
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
    if(l.pHead==NULL) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->pNext = p;
        l.pTail = p;
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

void XoaCuoi(LIST &l) {
    if(l.pHead == NULL) {
        return;
    }
    if(l.pHead->pNext == NULL) {
		XoaDau(l);
		return;
	}
    for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
        if(k->pNext=l.pTail) {
            delete l.pTail;
            k->pNext=NULL;
            l.pTail = k;
            return;
        }
    }
}


int main() {
    LIST l;
    KTDSLK(l);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        NODE *p = KhoiTaoNode(x);
        ThemVaoCuoi(l,p);
    }
    int vt;
    cin >> vt;
    if(vt == 0) {
        XoaDau(l);
    } else if(vt == n) {
        XoaCuoi(l);
    } else {
        int dem = 0;
         for(NODE *k = l.pHead; k != NULL; k = k->pNext) {
             dem++;
             if(vt == dem) {
                NODE *h = k->pNext;
                k->pNext = h->pNext;
                delete h;
             }
         }
    }
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data <<" ";
	}
}
