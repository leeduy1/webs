#include <bits/stdc++.h>
using namespace std;

bool Kiem_Tra_So_Nguyen_To(int n)
{
	if(n < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	int n;
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int j = 0;
	int arr2[100];
	for (int i = 0; i < n; i++) {
		if(Kiem_Tra_So_Nguyen_To(arr[i]) == false) {
			arr2[j] = arr[i];
			j++;
		}
	}
	
	for (int i = 0; i < j; i++) {
		cout << arr2[i] << " ";
	}
	

}
