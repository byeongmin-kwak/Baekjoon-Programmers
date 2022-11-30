#include <bits/stdc++.h>

using namespace std;

int dp[31];

int main() {
    
    int N;
    cin >> N;
    
    dp[1] = 0;
    dp[2] = 3;

    for (int i = 3; i <= N; i++) {
        if (i % 2 != 0) {
            dp[i] = 0;
        }
        else {
            dp[i] = dp[i-2] + 2;
            for (int j = 2; j < i; j += 2) {
                dp[i] += dp[i-j] * 2;
            }
        }
    }
    
    cout << dp[N] << endl;
}

