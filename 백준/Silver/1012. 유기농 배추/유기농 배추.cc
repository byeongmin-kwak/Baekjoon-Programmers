#include <bits/stdc++.h>

using namespace std;
 
int arr[50][50];
int x, y, k;
bool visited[50][50];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void dfs(int a, int b) {
    visited[a][b] = true;
    
    for (int i = 0; i < 4; i++) {
        int na = a + dir[i][0];
        int nb = b + dir[i][1];
        
        if(na >= 0 && nb >= 0 && na < x &&  nb < y) {
            if (visited[na][nb] == false && arr[na][nb] == 1) {
                dfs(na, nb);
            }
        }
    }
}

int main() {
    
    int T;
    cin >> T;
    
    while(T--) {
        cin >> x >> y >> k;
        int ans = 0;
        
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                arr[i][j] = 0;
                visited[i][j] = false;
            }
        }

        
        int nx, ny;
        for (int i = 0; i < k; i++) {
            cin >> nx >> ny;
            arr[nx][ny] = 1;
        }
        
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (visited[i][j] == false && arr[i][j] == 1) {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        
        cout << ans << '\n';
        
        
    }
}
