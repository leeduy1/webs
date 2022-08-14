#include <iostream>
using namespace std;

int main() {
	int hang,cot;
	cin >> hang >> cot;
	int a[hang][cot];
	for(int i = 0; i < hang; i++) {
		for(int j = 0; j < cot; j++) {
			cin >> a[i][j];
		}
	}
	
	// 1 2 3
    // 4 5 6
	
	int temp; 
	for(int j = 0; j < cot; j++) {  
	    temp = a[0][j];
	    a[0][j] = a[0][cot-j-1];
	    a[0][cot-j-1] = temp;
	}
	
	for (int j = cot-1; j >= 0; j--) {
		temp = a[hang-1][j];
		a[hang-1][j] = a[hang-1][cot-j-1];
		a[hang-1][cot-j-1] = temp;
	}
	
	for(int i = 0; i < hang; i++) {
		for(int j = 0; j < cot; j++) {
		    cout << a[i][j];
		}
	}
}
