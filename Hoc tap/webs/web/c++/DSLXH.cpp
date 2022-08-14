#include <bits/stdc++.h>
using namespace std;



int main() {
	int n;
	cout << "so Luong phan tu cua mang" << endl;
	cin >> n;
	cout << "Nhap Mang" << endl;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	
	
	int j = 0;
	int arr2[100];
	for (int i = 0; i < n; i++) {
		if(arr[i] != arr[i+1]) {
			arr2[j] = arr[i];
			j++;
		}
	}
	

    int a = 0;
	while(j > 0) {
		int dem = 0;
		for (int i = 0; i < n; i++) {
			if(arr2[a] == arr[i]) {
				dem++;
			}
		}
		cout << arr2[a] <<" "<< dem << endl;
		a++;
		j--;	
	}

	
}
