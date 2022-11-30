#include <bits/stdc++.h>

using namespace std;

int arr[1001][3];
int dp[1001][3];
 int main() {
    
     int N;
     cin >> N;
     
     for (int i = 1; i <= N; i++) {
         for (int j = 0; j < 3; j++) {
             cin >> arr[i][j];
         }
     }
     
     int result = 10000000;
     
     for (int first = 0; first < 3; first++) {
         
         for (int i = 0; i < 3; i++) {
             if (i == first) {
                 dp[1][i] = arr[1][i];
             }
             else {
                 dp[1][i] = 10000;
             }
         }
         
         for (int i = 2; i <= N; i++) {
             dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + arr[i][0];
             dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + arr[i][1];
             dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + arr[i][2];
         }
         
         for (int i = 0; i < 3; i++) {
             if (i == first) {
                 continue;
             }
             else {
                 result = min(result, dp[N][i]);
             }
         }
     }
     
     cout << result << endl;
}

