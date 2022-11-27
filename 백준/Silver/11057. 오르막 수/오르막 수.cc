#include <bits/stdc++.h>

using namespace std;

long long dp[1001][10];

int main() {
    
    int N;
    cin >> N;
    
    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += (dp[i-1][k]) % 10007;
            }
        }
    }
    
    int result = 0;
    
    for (int i = 0; i <= 9; i++) {
        result += dp[N][i] % 10007;
    }
    
    cout << result % 10007 << endl;
    
}

