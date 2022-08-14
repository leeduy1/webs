#include <bits/stdc++.h>
using namespace std;

void inputData(int *a, int &n) {
	for(int i = 0; i < n; i++) {
		cin >> *(a+i);
	//	rand();
	}
}

void outputData(int *a, int &n) {
	for(int i = 0; i < n; i++) {
		cout << *(a+i) << " ";
	}
	cout << endl;	
}


void removeOdd(int *a, int &n, int pos) {
	if(n < 0) {
		return;
	}
	for(int j = pos; j < n-1; j++) {
		*(a+j)= *(a+j+1);
	}
	n--;
}

void removeOddAll (int *a, int &n) {
	int pos = 0;
	for(int i = 0; i < n; i++) {
		if(*(a+i)%2!=0) {
			pos = i;
			removeOdd(a,n,pos);
		}
	}
}


int main() {
	int n;
	int a[100];
	int luachon;
	while(true) {
		cout << "=========== Menu ===========" << endl;
		cout << "1. Them phan tu" << endl;
		cout << "2. Xuat danh sach phan tu" << endl;
		cout << "3. Xoa tat ca cac so le trong danh sach" << endl;
		cout << "4. Thoat" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> luachon;
		if(luachon == 1) {
			cout << "Nhap so phan tu cua mang: ";
			cin >> n;
			inputData(a,n);
		} else if(luachon == 2) {
			outputData(a,n);
		} else if(luachon == 3) {
			removeOddAll(a,n);
		} else {
			break;
		}
	}
}
