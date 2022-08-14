#include <bits/stdc++.h>
using namespace std;

void so(int a[][3],int dong, int cot) {
	int b[10] = {0};
	
	for(int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			int temp = a[i][j];
			while(temp != 0) {
				int chiSo = temp % 10;
				temp = temp / 10;
				b[chiSo]++;
			}
		}
	}
	
	int min = INT_MAX;
	for(int i = 0; i < 10; i++) {
		if(min > b[i] && b[i] != 0) {
			min = b[i];
		}
	}
	
	for(int i = 0; i < 10; i++) {
		if(b[i] == min){
			cout << i << " ";
		}	
	}
}

int main() {
	int a[2][3] = {{126,258,347}, {45,51,60}};
	int dong = 2;
	int cot = 3;
	so(a,dong,cot);
}
