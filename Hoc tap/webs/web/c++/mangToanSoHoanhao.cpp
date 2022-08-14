#include <iostream>
using namespace std;

int laSoHoanHao(int n) {
	int sum = 0;
	for(int i = 1; i <= n/2; i++) {
		if(n % i == 0) {
			sum += i;
		}
	}
	if(n == sum) {
		return 1;
	} else {
		return 0;
	}
}



int laMangToanSoHoanHao(int a[], int n) {
	for(int i = 0; i < n; i++){
		if(laSoHoanHao(a[i]) == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int a[] = {1,2,3,4,5,6};
	int n = sizeof(a) / sizeof(a[0]);
	
	int kq = laMangToanSoHoanHao(a,n);
	
	if(kq == 1) {
		cout << "Mang toan so hoan hao ";
	} else {
		cout << "Mang khong toan so hoan hao ";
	}
}
