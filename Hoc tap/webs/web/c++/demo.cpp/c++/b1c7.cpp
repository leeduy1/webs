#include <iostream>
using namespace std;

struct node
{
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

void KhoiTaoDSLK(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; 
	p->pNext = NULL;
	return p;
}

void ThemVaoDau(LIST &l, NODE *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead; 
		l.pHead = p; 
	}
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
    

int main() {
    LIST l;
    KhoiTaoDSLK(l);
    int n;
    cin >> n;
    NODE *x = KhoiTaoNode(1);
    ThemVaoCuoi(l,x);
    for (int i = 2; i <= n; i++) {
    	NODE *p = KhoiTaoNode(i);
        ThemVaoDau(l,p);
    }
     for (int i = 2; i <= n; i++) {
    	NODE *p = KhoiTaoNode(i);
        ThemVaoCuoi(l,p);
    }
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << " ";
	}
}

