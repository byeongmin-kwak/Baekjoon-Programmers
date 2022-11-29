#include <bits/stdc++.h>

using namespace std;


int arr[2][100001];

int main() {
    
    int T;
    cin >> T;
    
    int n;
    while (T--) {
        int dp[2][100001] = {0};

        cin >> n;
    
        for (int i = 1; i <= n; i++) {
            cin >> arr[0][i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> arr[1][i];
        }
        
        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];
        
        dp[0][2] = dp[1][1] + arr[0][2];
        dp[1][2] = dp[0][1] + arr[1][2];
        
        for (int i = 3; i <= n; i++) {
            dp[0][i] = max(dp[1][i-2] + arr[0][i], dp[1][i-1] + arr[0][i]);
            dp[1][i] = max(dp[0][i-2] + arr[1][i], dp[0][i-1] + arr[1][i]);
        }
        
        cout << max(dp[0][n],dp[1][n]) << endl;
        
    }
}

