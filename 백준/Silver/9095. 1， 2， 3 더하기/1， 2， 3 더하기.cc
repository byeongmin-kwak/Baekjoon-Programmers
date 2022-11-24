#include <bits/stdc++.h>

using namespace std;

long long dp[11];

int main() {
    
    int t;
    cin >> t;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    int n;
    while (t--) {
        cin >> n;
        
        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        
        cout << dp[n] << endl;
        
    }
}
