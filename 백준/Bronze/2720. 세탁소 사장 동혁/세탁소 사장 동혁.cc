#include <bits/stdc++.h>

using namespace std;


int main() {

    int T;
    cin >> T;
    
    int c;
    while(T--) {
        cin >> c;
        int q = 0;
        int d = 0;
        int n = 0;
        int p = 0;
        if (c >= 25) {
            q = c / 25;
            c %= 25;
        }
        if (c >= 10) {
            d = c / 10;
            c %= 10;
        }
        if (c >= 5) {
            n = c / 5;
            c %= 5;
        }
        if (c >= 1) {
            p = c / 1;
        }
        
        cout << q << ' ' << d << ' ' << n << ' ' << p << '\n';
    }
    
}

