#include <iostream>
#include <queue>

using namespace std;

int N;
int map[100][100];
int island[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int answer = 10000;
int checkPoint[100][100];

void input() {
  
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
    }
  }
}

void checkIsland(int y, int x, int number) {
  
  queue<pair<int, int>> que;
  que.push({y, x});
  
  while(!que.empty()) {
    int y = que.front().first;
    int x = que.front().second;
    que.pop();
    
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      
      if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
        if (map[ny][nx] == 1 && island[ny][nx] == 0) {
          island[ny][nx] = number;
          que.push({ny, nx});
        }
      }
    }
  }
}

void bfs(int y, int x) {
  
  queue<pair<pair<int,int>, int>> que;
  que.push({{y, x}, 0});
  
  int initY = y;
  int initX = x;
  
  while(!que.empty()) {
    int y = que.front().first.first;
    int x = que.front().first.second;
    int cnt = que.front().second;
    que.pop();
    
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      
      if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
        if (map[ny][nx] == 0) {
          if (cnt+1 < checkPoint[ny][nx]) {
            checkPoint[ny][nx] = cnt+1;
            que.push({{ny,nx},cnt+1});
          }
        }
        else {
          if (island[ny][nx] != island[initY][initX]) {
            if (cnt < answer) answer = cnt;
          }
        }
      }
    }
  }
}

void clear() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      checkPoint[i][j] = 10000;
    }
  }
}

int main() {
  
  input();
  
  int number = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (map[i][j] == 1 && island[i][j] == 0) {
        island[i][j] = number;
        checkIsland(i, j, number);
        number++;
      }
    }
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (map[i][j] == 1) {
        clear();
        bfs(i, j);
      }
    }
  }
  
  cout << answer;
}
