#include <bits/stdc++.h>
using namespace std;

bool SNT(int n) {
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

void UKNT(int n) {
	for(int i = 2; i <= n; i++) {
		if(n % i == 0 && SNT(i) == false) {
			cout << i << " ";
		} 
	}
}


int main() {
	int n;
	cin >> n;
	UKNT(n);
}
