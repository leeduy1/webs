#include <bits/stdc++.h>
using namespace std;

void avg(int arr[3][5]) {
	int sum = 0;
	for(int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			sum += arr[i][j];
		}
	}
	cout  << "Average amount of food eaten per day by the whole family of monkeys: "<< fixed << setprecision(2) << sum / 5 << endl;
}

void monkey(int arr[3][5]) {
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	for(int j = 0; j < 5; j++) {
		sum1 += arr[0][j];
		sum2 += arr[1][j];
		sum3 += arr[2][j];
	}
	cout << "The least amount of food eaten during the week by any one monkey:" << endl;
	if(sum1 <= sum2 && sum1 <= sum3) {
		cout << "Monkey 1!";
	} else if(sum2 <= sum3) {
		cout << "Monkey 2!";
    } else {
    	"Monkey 3!";
	}
}

void amountOfFood(int arr[3][5]) {
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	for(int j = 0; j < 5; j++) {
		sum1 += arr[0][j];
		sum2 += arr[1][j];
		sum3 += arr[2][j];
	}
	cout << "The greatest amount of food eaten during the week by any one monkey: ";
	if(sum1 >= sum2 && sum1 >= sum3) {
		cout << sum1;
	} else if(sum2 >= sum3) {
		cout << sum2;
    } else {
    	cout << sum3;
	}
}
 
int main() {
	int arr[3][5];
	for(int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			cout << "arr[" << i << "]" << "[" << j << "]= ";
			cin >> arr[i][j];
			if(arr[i][j] < 0) {
				cout << "Invalid!";
				return 0;
			}
		}
	}
	avg(arr);
	monkey(arr);
	cout << endl;
	amountOfFood(arr);
	
	
}
