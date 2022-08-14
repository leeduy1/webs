#include <bits/stdc++.h>
using namespace std;

bool KiemTraSNT(int n) {
	if(n < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

void LietKeSNT(int n) {
	int i = 2;
	while(n > 0) {
		if(KiemTraSNT(i) == true) {
			cout << i << " ";
			n--;
		}
		i++;
	}
}

void LietKeFibonaci(int n) {
	int s1 = 1;
	int s2 = 1;
	cout << s1 << " " << s2 << " ";
	while(n > 2) {
		int s = s1 + s2;
		s1 = s2;
		s2 = s;
		cout << s << " ";
		n--;
	}
}

int main() {
	int n;
	cout << "Nhap so nguyen duong n: ";
	cin >> n;
	if(n <= 0) {
		cout << "Vui long nhap so Nguyen duong ";
	} else if(n == 1) {
		cout << 2 << endl;
		cout << 1;
	} else {
		LietKeSNT(n);
		cout << endl;
		LietKeFibonaci(n);
	}

}
