#include <string>
#include <vector>

#define INF 9876543

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    vector<vector<int>> minFare(n+1, vector<int>(n+1, INF));
    
    for (int i = 0; i < fares.size(); i++) {
        minFare[fares[i][0]][fares[i][1]] = fares[i][2];
        minFare[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for (int i = 1; i <= n; i++) {
        minFare[i][i] = 0;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (minFare[i][k] + minFare[k][j] < minFare[i][j]) {
                    minFare[i][j] = minFare[i][k] + minFare[k][j];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        answer = min(answer, minFare[s][i] + minFare[i][a] + minFare[i][b]);
    }
    
    
    
    
    
    return answer;
}