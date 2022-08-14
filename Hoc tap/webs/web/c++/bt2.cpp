#include <iostream>
using namespace std;

struct Student
{
 	string name;
	string _class;
	float mMath;
	float mPhysical;
	
	void input() {
		cout << "Nhap ten sinh vien: "<< endl;
		cin >> name;
		cout << "Nhap lop: " << endl;
		cin >> _class;
		cout << "Nhap diem mon toan: " << endl;
		cin >> mMath;
		cout << "Nhap diem mon ly: " << endl;
		cin >> mPhysical;
	}
	void output() {
		cout << "Ten sinh vien: " << name << endl;
		cout << "Lop: " << _class << endl;
		cout << "Diem mon toan: " << mMath << endl;
		cout << "Diem mon ly: " << mPhysical << endl;
	}
};

int main() {
	int n;
	Student s[50];
	int number;
	string name;

	while(true) {
		cout << " ======== MENU ========" << endl;
		cout << " 1. Them sinh vien" << endl;
		cout << " 2. Tim kiem mot sinh vien theo ten" << endl;
		cout << " 3. Tim kien mot sinh vien theo ten va chinh sua lop cua sinh vien do" << endl;
		cout << " 4. Thoat" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> n;
		if(n == 1) {
			cout << "Nhap so luong sinh vien can them: ";
			cin >> number;
			for(int i = 0; i < number; i++) {
				s[i].input();
			}
		} else if (n == 2) {
			cout << "Nhap ten sinh vien can tim kiem: ";
			cin >> name;
			for(int i =0; i < number; i++) {
				if(s[i].name == name) {
					s[i].output();
				}
			}
		} else if (n == 3) {
			int index = 0;
			cout << "Nhap ten sinh vien can thay doi lop: ";
			cin >> name;
			for(int i = 0; i < number; i++) {
				if(s[i].name == name) {
					s[i].output();
					index = i;
				}
			}
			string c_class;
			cout << "Nhap lop moi cho sinh vien: ";
			cin >> c_class;
			s[index]._class = c_class;
			cout << "Thong tin sinh vien sau khi thay doi lop: ";
			s[index].output();
		} else {
			break;
		}
	}
}
