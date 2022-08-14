#include <iostream>
using namespace std;

int main() {
	int a;
	cout << "Enter the number of elements in the array: ";
	cin >> a;
	int arr[a];
	for(int i = 0; i < a; i++) {
		cout << "arr[" << i << "]= ";
		cin >> arr[i];
	} 
	int n;
	int dem = 0;
	cout << "Input N: ";
	cin >> n;
	
	cout << "The elements greater than n in the array: " << endl;
	for (int i = 0; i < a; i++) {
		if(arr[i] > n) {
			cout << arr[i] << " ";
			dem++;
		}
	}
	if (dem == 0 ) {
		cout << "there is no element greater than n in the array! ";
	}
	return 0;
}
