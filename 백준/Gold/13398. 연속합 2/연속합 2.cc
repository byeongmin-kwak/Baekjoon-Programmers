#include <bits/stdc++.h>

using namespace std;

long arr[100001];
long dp[100001][2];

int main() {
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    dp[1][0] = arr[1];
    dp[1][1] = arr[1];
    long result = arr[1];
    
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(arr[i], dp[i-1][0] + arr[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        result = max(result, max(dp[i][0], dp[i][1]));
    }
    
    cout << result << endl;
    
}

