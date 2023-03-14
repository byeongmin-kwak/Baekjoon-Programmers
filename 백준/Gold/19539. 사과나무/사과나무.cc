#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    cin >> N;
    
    int sum = 0, sum2 = 0;
    
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        sum += h;
        sum2 += h / 2;
    }
    
    if (sum % 3 == 0) {
        if (sum2 >= sum / 3) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    else {
        cout << "NO" << '\n';
    }

}
