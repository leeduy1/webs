#include <iostream>
#include <math.h>
using namespace std;


int soChuSo(int n) {
	int dem = 0;
	while (n > 0) {
		n = n / 10;
		dem++;
	}
	return dem;
}

int tong(int n) {
	int tong = 0;
	int mu = soChuSo(n);
	while (n > 0) {
		int a = n % 10;
		tong += pow(a,mu);
		n = n / 10;
	}
	return tong;
}

int main() {
	int n;
	cin >> n;
	if(n == tong(n)) {
		cout << "Yes";
	} else {
		cout << "No";
	
}
