#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 100000000;
bool visited[25][25];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int cost_4Dir[25][25][4];

void dfs(vector<vector<int>>& board, int preDirection, int x, int y, int cost) {
    if (x == board.size()-1 && y == board.size()-1) {
        answer = min(answer, cost);
        return;
    }
    if (cost >= answer) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board.size()) {
            if (board[ny][nx] != 1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                
                int nCost = cost;
                if (preDirection != i) {
                    nCost += 600;
                }
                else {
                    nCost += 100;
                }
                
                if (cost_4Dir[nx][ny][i] > nCost) {
                    cost_4Dir[nx][ny][i] = nCost;
                    dfs(board, i, nx, ny, nCost);
                }
                
                
                visited[ny][nx] = false;
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            for (int k = 0; k < 4; ++k) {
            cost_4Dir[i][j][k] = 100000000;
            }
        }
    }
    
    dfs(board, -1, 0, 0, 0);
    
    
    answer -= 500;
    return answer;
}