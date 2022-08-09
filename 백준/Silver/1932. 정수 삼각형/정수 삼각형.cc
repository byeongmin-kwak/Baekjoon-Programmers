#include <bits/stdc++.h>

using namespace std;

int main()
{

    int arr[501][501];
    int dp[501][501];
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
        }
    }

    int max = 0;
    for (int i = 1; i<=n; i++) {
        if (dp[n][i] > max) {
            max = dp[n][i];
        }
    }
 
    cout << max;
}