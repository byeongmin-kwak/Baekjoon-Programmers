#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[1000][1000];
bool visited[1000][1000];
int answer[1000][1000];
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main() {
  cin >> n >> m;
  
  pair<int, int> start;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
      if (map[i][j] == 0) {
        answer[i][j] = 0;
      }
      else if (map[i][j] == 2) {
        start.first = i;
        start.second = j;
      }
      else {
        answer[i][j] = -1;
      }
    }
  }
  
  queue<pair<pair<int,int>,int>> que;
  que.push({start,0});
  
  while(!que.empty()) {
    int x = que.front().first.second;
    int y = que.front().first.first;
    int cnt = que.front().second;
    answer[y][x] = cnt;
    visited[y][x] = true;
    que.pop();
    
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      
      if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
        if (!visited[ny][nx] && map[ny][nx] == 1) {
          visited[ny][nx] = true;
          que.push({{ny,nx},cnt+1});
        }
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << answer[i][j] << ' ';
    }
    cout << '\n';
  }
  
  
}
