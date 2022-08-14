#include <iostream>
#include <stack>

using namespace std;

int main() {
	string s;
	stack<char> st;
	cout << "Nhap bieu thuc: ";
	getline(cin,s);
	for(int i = 0; i < s.length(); i++) {
		st.push(s[i]);
	}
	int demx = 0;
	int demy = 0;
	int dema = 0;
	int demb = 0;
	while(!st.empty()) {
		char z = st.top();
		if(z == '{') {
			demx++;
		}
		if(z == '}') {
			demy++;
		}
		if(z == '(') {
			dema++;
		}
		if(z==')') {
			demb++;
		}
		st.pop();
	}
	
	if(dema == demb && demx == demy) {
		cout << "Chuong trinh hop le";
	} else {
		cout << "Chuong trinh khong hop le";
	}
}
