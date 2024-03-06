#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int N, M;
int init[8][8];
int laboratory[8][8];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ans = 0;
vector<pair<int, int>> wall;


void input() {
  cin >> N >> M;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> laboratory[i][j];
      init[i][j] = laboratory[i][j];
    }
  }
}

void virus(int y, int x) {
  queue<pair<int, int>> que;
  que.push({y, x});
  
  while(!que.empty()) {
    int y = que.front().first;
    int x = que.front().second;
    que.pop();
    
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      
      if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
        if (laboratory[ny][nx] == 0) {
          laboratory[ny][nx] = 2;
          que.push({ny, nx});
        }
      }
    }
  }
}

void solve(int depth, int ni) {
  if (depth == 3) {
    
    for (int i = 0; i < wall.size(); i++) {
      int y = wall[i].first;
      int x = wall[i].second;
      laboratory[y][x] = 1;
    }
    
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (laboratory[i][j] == 2) {
          virus(i, j);
        }
      }
    }
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (laboratory[i][j] == 0) {
          cnt++;
        }
      }
    }
    ans = max(ans, cnt);

        
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        laboratory[i][j] = init[i][j];
      }
    }
    for (int i = 0; i < wall.size(); i++) {
      int y = wall[i].first;
      int x = wall[i].second;
      laboratory[y][x] = 1;
    }
    return;
  }
  
  for (int i = ni; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (laboratory[i][j] == 0) {
        laboratory[i][j] = 1;
        wall.push_back({i, j});
        solve(depth+1, i);
        wall.pop_back();
        laboratory[i][j] = 0;
      }
    }
  }
}

int main() {
  
  input();
  
  solve(0, 0);
  
  cout << ans;
  
}