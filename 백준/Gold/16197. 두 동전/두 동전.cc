#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, ans;
char board[21][21];
vector<pair<int,int>> coin;
bool visited[21][21][21][21];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct Coins { int x1, y1, x2, y2, cnt; };


void input() {
  cin >> N >> M;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'o') {
        coin.push_back({i,j});
      }
    }
  }
}

bool overRange(int x, int y) {
  if (x < 0 || x >= M || y < 0 || y >= N) {
    return true;
  }
  return false;
}

void bfs() {
  
  queue<Coins> que;
  que.push({coin[0].second, coin[0].first, coin[1].second, coin[1].first, 0});
  visited[coin[0].second][coin[0].first][coin[1].second][coin[1].first] = true;

  
  while (!que.empty()) {
    Coins current = que.front();
    que.pop();
    
    if (current.cnt > 10) {
      break;
    }
    
    for (int i = 0; i < 4; i++) {
      int nx1 = dx[i] + current.x1;
      int ny1 = dy[i] + current.y1;
      int nx2 = dx[i] + current.x2;
      int ny2 = dy[i] + current.y2;
      
      // 둘중 하나만 나갔을 때
      if ((!overRange(nx1, ny1) && overRange(nx2, ny2)) || (overRange(nx1, ny1) && !overRange(nx2, ny2))) {
        if (current.cnt+1 > 10) {
          ans = -1;
          return;
        }
        ans = current.cnt+1;
        return;
      }
      
      // 두개 다 나갔을 때
      if (overRange(nx1, ny1) && overRange(nx2, ny2)) {
        continue;
      }
      
      // 두개 모두 벽에 부딪힌 경우
      if (board[ny1][nx1]=='#' && board[ny2][nx2]=='#'){
        continue;
      }
      
      // 둘 중 하나만 벽이면, 안 움직이는 건 원상복귀
      if (board[ny1][nx1]=='#'){
          nx1 = current.x1;
          ny1 = current.y1;
      } else if (board[ny2][nx2]=='#'){
          nx2 = current.x2;
          ny2 = current.y2;
      }
      
      
      if (!visited[nx1][ny1][nx2][ny2]){
        que.push({ nx1, ny1, nx2, ny2, current.cnt+1});
        visited[nx1][ny1][nx2][ny2] = true;
      }
    }
  }
  ans = -1;
}

int main() {
  
  input();
  
  bfs();
  
  cout << ans;
}
