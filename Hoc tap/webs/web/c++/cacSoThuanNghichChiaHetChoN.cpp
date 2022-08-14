#include <bits/stdc++.h>
using namespace std;

int SoThuanNghich(int n) {
	int sum = 0;
	while(n != 0) {
		int a = n % 10;
		sum = (sum * 10) + a;
		n = n / 10;
	} 
	return sum;
}

int main() {
	int k;
	cin >> k;
	int i = 10000000;
	while(i < 100000000) {
		if(i == SoThuanNghich(i) && i % k == 0) {
			cout << i << " ";
		}
		i++;
	}
	return 0;
}
