#include<bits/stdc++.h>

using namespace std;

struct node {
    int data; // dữ liệu của node
    node *pLeft; //node bên trái của cây => cây con trái
    node *pRight; //node bên phải của cây
};

//Khởi tạo cây(tree)

void KhoiTaoCay(node *t) {
    t = NULL; // cây rỗng
}

// H� m thêm phần tử x v� o cây nhị phân
void ThemNodeVaoCay(node *t, int x) {
    // nếu cây rỗng
    if (t == NULL) {
        node *p = new node; // Khởi tạo 1 cái node để thêm v� o cây
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p; // node p chính l�  node gốc 
    }
    else { // Cây có tồn tại phần tử
        if (t->data > x){//Nếu phần tử thêm v� o nhỏ hơn node gốc ===> Thêm nó v� o bên trái
            ThemNodeVaoCay(t->pLeft, x); // duyệt qua trái để thêm phần tử x
        }
        else if (t->data < x) {
            ThemNodeVaoCay(t->pRight, x); // duyệt qua bên phải
        }
    }
}

//H� m xuất cây nhị phân theo NLR
void Duyet_NLR(node *t) {
    if (t != NULL) {
        cout << t->data << " ";
        Duyet_NLR(t->pLeft); // duyệt qua trái
        Duyet_NLR(t->pRight); //duyệt qua phải
    }
}

//h� m nhập dữ liệu

void Menu(node *t ){

    while(true) {
        cout <<"\n\n\t\t=================MENU===============";
        cout <<"\n1. Nhap du lieu";
        cout <<"\n2. Xuat du lieu";
        cout <<"\n0. Ket thuc";
        cout <<"\n\n\t\t====================================";
        int luachon;

        cout << "\nNhap lua chon: ";
        cin >> luachon;
        if (luachon < 0 || luachon > 2) {
            cout << "\nLua chon khong hop le";
            system("pause");
        }
        else if (luachon == 1) {
            int x;
            cout << "\nNhap so nguyen x: ";
            cin >> x;
            ThemNodeVaoCay(t, x);
        }
        else if (luachon == 2) {
            cout <<"\n\t\tDuyet cay theo NLR";
        }
        else {
            break;
        }
    }
}

int main() {

    node* t;
    KhoiTaoCay(t);
    Menu(t);

    return 0;
}
