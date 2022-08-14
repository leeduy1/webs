#include <bits/stdc++.h>
using namespace std;

int laSoHoanHao(int n) {
	int sum = 0;
	for(int i = 1; i <= n/2; i++) {
		if(n % i == 0) {
			sum += i;
		}
	}
	if(n == sum) {
		return 1;
	} else {
		return 0;
	}
}

int SHHDauTien(int a[], int n) {
	for(int i = 0; i < n; i++) {
		if(laSoHoanHao(a[i]) == 1) {
			return a[i];
		}
	} 
	return -1;
}

int vitriSHHNhoNhat(int a[], int n) {
	int idx = SHHDauTien(a,n);
	if(idx == -1) {
		return -1;
	} 
	int vt = 0;
	for (int i = 0; i < n; i++) {
		if(laSoHoanHao(a[i]) == 1 && a[i] <= idx) {
			idx = a[i];
			vt = i;
		}
	}
	return vt;
}

int main() {
	int a[] = {1,2,3,4,5,6};
	int n = sizeof(a) / sizeof(a[0]);	
	
	int kq = vitriSHHNhoNhat(a,n);
	
	if(kq != -1) {
		cout << kq;
	} else {
		cout << "No";
	}
	
}
