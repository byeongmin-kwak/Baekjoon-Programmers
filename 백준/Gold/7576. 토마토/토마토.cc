#include <bits/stdc++.h>

using namespace std;

int tomato[1000][1000];
int M, N;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
bool visited[1000][1000];
queue<pair<int,int>> que;

void bfs() {
    while(!que.empty()) {
        pair<int,int> xy = que.front();
        que.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = xy.first + dir[i][0];
            int ny = xy.second + dir[i][1];
            
            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (tomato[nx][ny] == 0) {
                    tomato[nx][ny] = tomato[xy.first][xy.second] + 1;
                    que.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    
    cin >> M >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tomato[i][j];
            if(tomato[i][j] == 1) {
                que.push(make_pair(i,j));
            }
        }
    }
    bfs();

    
    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tomato[i][j] == 0) {
                cout << -1 << '\n';
                return 0;
            }
            result = max(result, tomato[i][j]);
        }
    }
    
    cout << result - 1 << '\n';

}
