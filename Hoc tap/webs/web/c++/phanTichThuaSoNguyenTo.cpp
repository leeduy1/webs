#include <iostream>
using namespace std;

int TongCCS(int n) {
	int sum = 0;
	while(n != 0) {
		int a = n % 10;
		sum += a;
		n = n / 10;
	}
	return sum;
}

void TSSNT(int n) {
	int i = 2;
	while(n != 0) {
		if(n % i == 0) {
			cout << i << " ";
			n = n / i;
		} else {
			i++;
		}
	}
}

int main() {
	int n;
	cin >> n;
	TSSNT(n);
}
