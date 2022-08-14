#include <iostream>
using namespace std;

int main() {
	int a[7];
	for(int i = 0; i < 7; i++) {
		cin >> a[i];
	}
	int n;
	cin >> n;
	int dem = 0;
	
	for(int i = 0; i < 7; i++) {
		if(n == a[i]) {
			cout << i << " ";
			dem ++;
		}
	}
	if(dem == 0) {
		cout << "N";
	}
	return 0;
}
