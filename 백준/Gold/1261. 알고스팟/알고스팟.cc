#include <iostream>
#include <queue>

using namespace std;

int M, N;
int maze[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int cntBreakDoor[100][100];
int ans = 10000;

void input() {
  
  cin >> M >> N;
  
  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 0; j < M; j++) {
      maze[i][j] = s[j]-'0';
    }
  }
}

void init() {
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cntBreakDoor[i][j] = 10000;
    }
  }
  cntBreakDoor[0][0] = 0;
  
}

void bfs() {
  
  queue<pair<pair<int,int>, int>> que;
  que.push({{0,0},0});
  
  while(!que.empty()) {
    int y = que.front().first.first;
    int x = que.front().first.second;
    int cnt = que.front().second;
    que.pop();
    
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      
      if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
        if (ny == N-1 && nx == M-1) {
          if (cnt < ans) ans = cnt;
          continue;
        }
        if (cnt < cntBreakDoor[ny][nx]) {
          cntBreakDoor[ny][nx] = cnt;
          if (maze[ny][nx] == 1) {
            que.push({{ny,nx},cnt+1});
          }
          else {
            que.push({{ny,nx},cnt});
          }
        }
      }
    }
  }
  
}

int main() {
  
  input();

  init();
  
  bfs();
  
  if (M == 1 && N == 1) ans = 0;
  cout << ans;
  
}
