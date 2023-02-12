#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[100][100];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
bool visited[100][100];
int dist[100][100];
queue<pair<int,int>> que;

void bfs(int x, int y) {
    visited[x][y] = true;
    dist[x][y]++;
    que.push(make_pair(x, y));
    
    while(!que.empty()) {
        x = que.front().first;
        y = que.front().second;
        que.pop();
        
        for (int i = 0; i < 4; i++) {
            
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            
            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (visited[nx][ny] == false && arr[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    que.push(make_pair(nx, ny));
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
        
        
    }
    
}

int main() {
        
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < M; j++) {
            arr[i][j] = input[j] - '0';
        }
    }
    
    bfs(0,0);
    
    cout << dist[N-1][M-1] << endl;
    
    
}
