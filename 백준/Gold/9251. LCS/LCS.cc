#include <bits/stdc++.h>

using namespace std;

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    int dp[1001][1001];

    int maxNum = 0;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
            maxNum = max(maxNum, dp[i][j]);
        }
    }

    cout << maxNum;

}
