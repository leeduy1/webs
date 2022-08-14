#include <iostream>
using namespace std;

int main() {
	int dong,cot;
	cin >> dong >> cot;
	int a[dong][cot];
	
	for(int i = 0; i < dong; i++) {
		for (int j = 0; j < cot; j++) {
			cin >> a[i][j];
		}
	}
	
	for(int i = 0; i < dong; i++) {
		if (i == 0 || i == (dong - 1)) {
            for (int j = cot - 1; j >= 0; j--) {
                cout << a[i][j] << " ";
            }
        }
        else {
            for (int j = 0; j < cot; j++){
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
	}
	return 0;
}
