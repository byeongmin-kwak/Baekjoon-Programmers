#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
bool visited[100][100];

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    queue<pair<pair<int,int>,int>> que;
    que.push({{0,0},1});
    visited[0][0] = true;
    bool flag = false;
    
    while(!que.empty()) {
        if (flag) {
            break;
        }
        int x = que.front().first.first;
        int y = que.front().first.second;
        int cnt = que.front().second;
        que.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < maps[0].size() && ny >= 0 && ny < maps.size()) {
                if (maps[ny][nx] == 1 && !visited[ny][nx]) {
                    if (nx == maps[0].size()-1 && ny == maps.size()-1) {
                        answer = cnt+1;
                        flag = true;
                        break;
                    }
                    else {
                        que.push({{nx,ny},cnt+1});
                        visited[ny][nx] = true;
                    }
                }
            }
        }
    }
    if (!flag) {
        answer = -1;
    }
    
    
    return answer;
}