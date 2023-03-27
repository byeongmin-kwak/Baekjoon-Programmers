#include <bits/stdc++.h>

using namespace std;

int arr[10][10];
int N, M, K;
int ans = -10000, sum = 0;
int visited[10][10];
int dxdy[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void solve(int depth) {
    if (depth == K) {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0) {
                visited[i][j] += 1;
                for (int index = 0; index < 4; index++) {
                    int dy = i+dxdy[index][0];
                    int dx = j+dxdy[index][1];
                    if (dy >= 0 && dy < N && dx >= 0 && dx < M)
                        visited[dy][dx] += 1;
                }
                sum += arr[i][j];
                
                solve(depth+1);
                
                sum -= arr[i][j];
                visited[i][j] -= 1;
                for (int index = 0; index < 4; index++) {
                    int dy = i+dxdy[index][0];
                    int dx = j+dxdy[index][1];
                    if (dy >= 0 && dy < N && dx >= 0 && dx < M)
                        visited[dy][dx] -= 1;
                }
            }
        }
    }
}

int main() {
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    
    solve(0);
    
    cout << ans << '\n';
}
