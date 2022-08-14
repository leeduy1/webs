#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
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
	int n;
    cin >> n;
    int res = 0;
    for (int a = 2; a <= n / 2; ++a) {
       if(isPrime(a) && isPrime(n - a)) {
       	res++;
	   }
    }
    cout << res;
    return 0;
	
}
