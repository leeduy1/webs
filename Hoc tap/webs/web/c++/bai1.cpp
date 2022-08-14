#include <iostream>
using namespace std;

int daoNguoc(int n) {
	int sum = 0;
	while(n != 0) {
		int temp = n % 10;
		sum = (sum * 10) + temp;
		n = n / 10;
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	
	if(n > 9 && n < 100) {
		cout << daoNguoc(n);
	} else {
		cout << "N";
	}
	
}
