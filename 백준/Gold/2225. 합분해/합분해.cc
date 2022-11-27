#include <bits/stdc++.h>

using namespace std;

long long dp[201][201];

int main() {
    
    int N, K;
    cin >> N >> K;
    
    for (int n = 0; n <= N; n++) {
        dp[1][n] = 1;
    }
    
    for (int k = 2; k <= K; k++) {
        for (int n = 0; n <= N; n++) {
            for (int l = 0; l <= n; l++) {
                dp[k][n] += dp[k-1][l];
            }
            dp[k][n]%=1000000000;
        }
    }
    
    cout << dp[K][N] << endl;
    
    
}
