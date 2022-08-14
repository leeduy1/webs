#include <iostream>
using namespace std;

int main() {
	int n;
	int dem = 0;
	int sum = 0;
	
	do {
		cin >> n;
		if (n % 2 != 0) {
			sum += n;
		}
		dem++;
	} while (n >= 0 && dem < 10);
	if(sum < 0) {
		cout << 0;
	} else {
		cout << sum;
	}
	
	return 0;
}
