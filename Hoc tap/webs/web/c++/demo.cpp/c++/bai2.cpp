#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	if(n > 0 && n < 10000) {
		if (n == 1) {
			cout << 10000;
		} else if (n > 1 && n <= 30) {
			cout << 10000 + (n-1) * 8000;
		} else if (n > 30) {
			cout << n * 7000;
		}
	} else {
		cout << 'N';
	}
	return 0;
}
