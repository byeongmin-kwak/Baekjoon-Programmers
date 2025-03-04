#include <string>
#include <vector>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int func(vector<vector<string>>& board, int y, int x) {
    int result = 0;
    
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        
        if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) {
            continue;
        } else {
            if (board[ny][nx] == board[y][x]) {
                result++;
            }
        }
        
    }
        
    return result;
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    answer = func(board, h, w);
    
    return answer;
}