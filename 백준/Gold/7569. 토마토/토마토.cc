#include <bits/stdc++.h>

using namespace std;

int tomato[100][100][100];
int M, N, H;
int dir[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,0,1},{0,1,0},{0,0,-1}};

struct xyz {
    int z, y, x;
};

queue<xyz> que;

void bfs() {
    while(!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        int z = que.front().z;
        
        que.pop();
        
        for (int i = 0; i < 6; i++) {
            int nx = x + dir[i][2];
            int ny = y + dir[i][1];
            int nz = z + dir[i][0];
            
            if (nx >= 0 && ny >= 0 && nz >= 0 && nx < M && ny < N && nz < H) {
                if (tomato[nz][ny][nx] == 0) {
                    tomato[nz][ny][nx] = tomato[z][y][x] + 1;
                    que.push({nz,ny,nx});
                }
            }
        }
    }
}

int main() {
    
    cin >> M >> N >> H;
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1) {
                    que.push({i,j,k});
            }

            }
        }
    }
    bfs();

    
    int result = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (tomato[i][j][k] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                result = max(result, tomato[i][j][k]);
            }
        }
    }
    cout << result - 1 << '\n';
}
