#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i; j >= 0; j--) {
            if(a[i] != a[j]) {
                q.push(a[i]);
            }
        }
    }
     while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}
