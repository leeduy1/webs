#include <bits/stdc++.h>


using namespace std;

void sum(double month[]) {
	double sum = 0;
	for(int i=0; i<12;i++) {
		sum += month[i];
	}
	cout << "Total rainfall for the year: " << sum << endl;
}

void avg(double month[]) {
	double sum = 0;
	for(int i=0; i<12;i++) {
		sum += month[i];
	}
	cout << "The average monthly rainfall: " << fixed << setprecision(2) << sum / 12 << endl;
}

void max(double month[]) {
	int j = 0;
	double max = month[0];
	for (int i = 0; i < 12; i++) {			
		if(month[i] >= max) {
			max = month[i];
			j = i;
		}
	}
	cout << "The month with the highest rainfall: "<< j+1 << endl;
}

void min(double month[]) {
	int j = 0;
	double min = month[0];
	for (int i = 0; i < 12; i++) {			
		if(month[i] <= min) {
			min = month[i];
			j = i;
		}
	}
	cout << "The month with the lowest rainfall: "<< j+1;
}


int main() {
	double month[12];
	for(int i=0; i<12;i++) {
		cout << "Input month " << i+1 << ": ";
		cin >> month[i];
		if (month[i] < 0) {
			cout << "Invalid";
			return 0;
		}
	}	
	sum(month);
	avg(month);
	max(month);
	min(month);
}
