#include <iostream>
using namespace std;

void xuatMang(int n, int* arr) {
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int n;
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	int* arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	xuatMang(n,arr);
}
