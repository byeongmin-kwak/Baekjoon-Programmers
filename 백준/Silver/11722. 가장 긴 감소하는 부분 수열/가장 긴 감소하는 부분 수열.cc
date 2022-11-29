#include <bits/stdc++.h>

using namespace std;

int arr[1001];
int dp[1001];

int main() {

    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    dp[1] = 1;
    
    int result = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[j] > arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }
    
    cout << result << endl;
}

