#include <string>
#include <vector>

using namespace std;

bool visited[200];
int answer = 0;

void solve(int n, vector<vector<int>> &computers, int current) {
    visited[current] = true;
    for (int i = 0; i < n; i++) {
        if (computers[current][i] == 1) {
            if (visited[i]) continue;
            solve(n, computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer++;
            solve(n, computers, i);
        }
    }
    
    return answer;
}