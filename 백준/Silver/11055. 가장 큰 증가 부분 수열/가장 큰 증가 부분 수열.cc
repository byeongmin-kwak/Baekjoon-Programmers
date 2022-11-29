#include <bits/stdc++.h>

using namespace std;

int arr[1001];
long long dp[1001];

int main() {

    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    dp[1] = arr[1];
    
    long long result = dp[1];
    for (int i = 2; i <= N; i++) {
        dp[i] = arr[i];
        for (int j = 1; j < i; j++) {
            if (dp[i] > dp[j]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        result = max(result, dp[i]);
    }
    
    cout << result << endl;
}

