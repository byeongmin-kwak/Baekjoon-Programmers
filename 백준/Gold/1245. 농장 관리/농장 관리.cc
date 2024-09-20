#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int arr[100][70];
bool visited[100][70];
int ans = 0;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs(int y, int x) {
  bool check = false;
  
  queue<pair<int, int>> que;
  que.push({y, x});
  visited[y][x] = true;
  
  while (!que.empty()) {
    int y = que.front().first;
    int x = que.front().second;
    
    que.pop();
    
    for (int i = 0; i < 8; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      
      if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
        if (arr[ny][nx] > arr[y][x]) {
          check = true;
        }
        else if (arr[ny][nx] == arr[y][x]) {
          if (!visited[ny][nx]) {
            que.push({ny, nx});
            visited[ny][nx] = true;
          }
        }
      }
    }
  }
  
  if (!check) {
    ans++;
  }
}

int main() {
  
  
  cin >> N >> M;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
    }
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!visited[i][j]) {
        bfs(i, j);
      }
    }
  }
  
  cout << ans << endl;
}
