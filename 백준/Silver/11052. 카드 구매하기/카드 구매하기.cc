#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int arr[1001];

int main() {
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    dp[1] = arr[1];
    
    int maxNum;
    for (int i = 2; i <= n; i++) {
        dp[i] = arr[i];
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = max(dp[i], dp[j]+dp[i-j]);
        }
    }
    
    cout << dp[n] << endl;
    
}
