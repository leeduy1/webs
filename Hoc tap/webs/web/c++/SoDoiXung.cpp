#include <bits/stdc++.h>
using namespace std;

int soDoiXung(int n) {
	int sum = 0;
	while(n != 0) {
		int a = n % 10;
		sum = (sum * 10) + a;
		n = n / 10;
	} 
	return sum;
		
}

int main() {
	int n;
	cin >> n;
	if(n == soDoiXung(n)) {
		cout << "Yes";
	} else {
		cout << "No";
	}
}

