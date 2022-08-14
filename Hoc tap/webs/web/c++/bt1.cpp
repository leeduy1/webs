#include <iostream>
using namespace std;

void boTatCaCacSoLe(int n, int* a) {
	for(int i = 0; i < n; i++) {
		if(*(a+i) % 2 == 0) {
			cout << *(a+i) << " ";
		}
	}
}

void xuatMang(int n, int* a) {
	for(int i = 0; i < n; i++) {
		cout << *(a+i) << " ";
	}
}

int main() {
	int n;
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> *(a+i);
	}
	xuatMang(n,a);
	cout << endl;
	boTatCaCacSoLe(n,a);
	return 0;
}
