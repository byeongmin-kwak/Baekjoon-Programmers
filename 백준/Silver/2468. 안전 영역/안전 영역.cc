#include <bits/stdc++.h>

using namespace std;

int arr[100][100];
bool visited[100][100];
int N;
int dxdy[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
int minNum = 100, maxNum = 1;
int ans = 0;

void dfs(int y, int x, int h) {
    if (x >= 0 && x < N && y >= 0 && y < N) {
        if (arr[y][x] > h && visited[y][x] == false) {
            visited[y][x] = true;
            for (int i = 0; i < 4; i++) {
                int dx = x + dxdy[i][0];
                int dy = y + dxdy[i][1];
                dfs(dy, dx, h);
            }
        }
    }
}

int main() {
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            minNum = min(minNum, arr[i][j]);
            maxNum = max(maxNum, arr[i][j]);
        }
    }
    
    for (int h = minNum-1; h < maxNum; h++) {
        int cnt = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visited[i][j] = false;
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] > h && visited[i][j] == false) {
                    cnt++;
                    dfs(i,j,h);
                }
            }
        }
        ans = max(ans, cnt);
        
    }
    
    cout << ans << '\n';
}
