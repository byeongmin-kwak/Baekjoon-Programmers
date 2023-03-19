#include <bits/stdc++.h>

using namespace std;

char arr[100][100];
int N;
int dxdy[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
bool visited[100][100];
int ans1 = 0, ans2 = 0;

void dfs1(int y, int x, char c) {
    if (y >= 0 && y < N && x >= 0 && x < N) {
        if (arr[y][x] == c && visited[y][x] == false) {
            visited[y][x] = true;
            
            for (int i = 0; i < 4; i++) {
                int dx = x + dxdy[i][0];
                int dy = y + dxdy[i][1];
                dfs1(dy,dx,c);
            }
        }
    }
}

void dfs2(int y, int x, char c1, char c2) {
    if (y >= 0 && y < N && x >= 0 && x < N) {
        if ((arr[y][x] == c1 || arr[y][x] == c2) && visited[y][x] == false) {
            visited[y][x] = true;
            
            for (int i = 0; i < 4; i++) {
                int dx = x + dxdy[i][0];
                int dy = y + dxdy[i][1];
                dfs2(dy,dx,c1,c2);
            }
        }
    }
}

int main() {
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0 ; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == false) {
                if (arr[i][j] == 'R') {
                    ans1++;
                    dfs1(i,j,'R');
                }
                else if (arr[i][j] == 'G') {
                    ans1++;
                    dfs1(i,j,'G');
                }
                else {
                    ans1++;
                    dfs1(i,j,'B');
                }
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == false) {
                if (arr[i][j] == 'R' || arr[i][j] == 'G') {
                    ans2++;
                    dfs2(i,j,'R', 'G');
                }
                else {
                    ans2++;
                    dfs2(i,j,'B','B');
                }
            }
        }
    }
    
    
    cout << ans1 << ' ' << ans2 << '\n';

    

}
