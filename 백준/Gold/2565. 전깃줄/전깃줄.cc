#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    int dp[101];

    vector<pair<int, int> > v(n+1);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    int maxNum = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (v[j].second < v[i].second and dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                maxNum = max(maxNum, dp[i]);
            }
        }
    }
    cout << n - maxNum;
}
