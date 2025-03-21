#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer;
    
    int dp[info.size()+1][m+1];
    
    for (int i = 0; i < info.size()+1; i++) {
        for (int j = 0; j < m+1; j++) {
           dp[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= info.size(); i++) {
        for (int j = 1; j <= m; j++) {
            
            // b가 훔칠 수 있다면 비교해서 최적값(a가 훔치냐 b가 훔치냐), b가 못 훔치면 반드시 a가 훔쳐야 된다.
            if (info[i-1][1] < j) {
                dp[i][j] = min(dp[i-1][j-info[i-1][1]], dp[i-1][j]+info[i-1][0]);
            } else {
                dp[i][j] = dp[i-1][j]+info[i-1][0];
            }
        }
    }
    
    answer = dp[info.size()][m];
    if (answer >= n) answer = -1;
    
    // for (int i = 0; i < info.size()+1; i++) {
    //     for (int j = 0; j < m+1; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
        
    return answer;
}