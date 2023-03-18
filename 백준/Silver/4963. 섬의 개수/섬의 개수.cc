#include <bits/stdc++.h>

using namespace std;

int arr[50][50];
bool visited[50][50];
int w, h;
int dxdy[8][2] = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};

void dfs(int y, int x) {
    if (x >= 0 && x < w && y >= 0 && y < h) {
        if (arr[y][x] == 1 && visited[y][x] == false) {
            visited[y][x] = true;
            for (int i = 0; i < 8; i++) {
                int dx = x + dxdy[i][0];
                int dy = y + dxdy[i][1];
                dfs(dy, dx);
            }
        }
    }
}

int main() {
    
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }
        
        int ans = 0;
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
                visited[i][j] = false;
            }
        }
        
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {

                if (arr[i][j] == 1 && visited[i][j] == false) {
                    ans++;
                    dfs(i,j);
                }
            }
        }
        
        cout << ans << '\n';
    }
}