#include <bits/stdc++.h>

using namespace std;


int main() {

    int n;
    cin >> n;
    
    int ans = 0;
    if (n >= 5) {
        int temp = n / 5;
        while (temp) {
            if ((n - (temp * 5)) % 2 == 0) {
                ans = temp;
                n -= temp*5;
                break;
            }
            else {
                temp--;
            }
        }
    }
    if (n >= 2) {
        ans += n / 2;
        n %= 2;
    }
    
    if (n == 0) {
        cout << ans;
    }
    else {
        cout << -1;
    }
}

