#include <bits/stdc++.h>
using namespace std;

bool kiemTraSoNguyenTo(int n) {
	if(n < 2) {
		return false;
	}
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int a;
	cout << "nhap a: ";
	cin >> a;
	int i = 0;
	while (a > 0) {
		i++;
		if(kiemTraSoNguyenTo(i) == true) {
			cout << i << " ";
			a--;
		}
	}
}
