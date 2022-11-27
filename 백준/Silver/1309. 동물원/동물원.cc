#include <bits/stdc++.h>

using namespace std;

unsigned long long dp[100001][2];

int main() {

    int N;
    cin >> N;
    
    dp[1][0] = 1;
    dp[1][1] = 2;
    
    for (int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % 9901;
        dp[i][1] = ((dp[i-1][0] * 3 + dp[i-1][1] * 2 ) - dp[i][0] ) % 9901;
        
    }

    cout << (dp[N][0] + dp[N][1]) % 9901 << endl;
}

