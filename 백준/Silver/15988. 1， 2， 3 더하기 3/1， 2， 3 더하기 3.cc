#include <bits/stdc++.h>

using namespace std;

long long dp[1000000];

int main() {

    int T;
    cin >> T;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    int n;
    while (T--) {
        cin >> n;
        
        for (int i = 4; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
        }
            
            
        cout << dp[n] << endl;
    }
    
}

