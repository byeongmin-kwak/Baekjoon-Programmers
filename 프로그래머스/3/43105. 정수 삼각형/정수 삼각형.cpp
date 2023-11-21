#include <string>
#include <vector>

using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    dp[0][0] = triangle[0][0];
    
    for (int i = 1; i < triangle.size(); i++) {
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        for (int j = 1; j < triangle[i].size(); j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }
    
    for (int i = 0; i < triangle.size(); i++) {
        answer = max(answer, dp[triangle.size()-1][i]);
    }
    
    return answer;
}