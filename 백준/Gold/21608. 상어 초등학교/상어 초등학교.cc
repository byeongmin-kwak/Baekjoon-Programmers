#include <iostream>
#include <vector>

using namespace std;

int seat[20][20];
int N;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int answer = 0;
vector<int> v[401];

void position(int a, int b, int c, int d, int e) {
  int cnt = -1;
  int empty = 0;
  int x, y;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (seat[i][j] != 0) {
        continue;
      }
      int tmpCnt = 0;
      int tmpEmpty = 0;
      for (int k = 0; k < 4; k++) {
        int nx = j + dx[k];
        int ny = i + dy[k];
        
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
          if (seat[ny][nx] == b || seat[ny][nx] == c || seat[ny][nx] == d || seat[ny][nx] == e) {
            tmpCnt++;
          }
          else {
            if (seat[ny][nx] == 0) {
              tmpEmpty++;
            }
          }
        }
      }
      if (tmpCnt > cnt) {
        cnt = tmpCnt;
        empty = tmpEmpty;
        x = j;
        y = i;
      }
      else if (tmpCnt == cnt) {
        if (tmpEmpty > empty) {
          empty = tmpEmpty;
          x = j;
          y = i;
        }
      }
    }
  }
  seat[y][x] = a;
}

void solve(int x, int y) {
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    
    if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
      for (int elem : v[seat[y][x]]) {
        if (elem == seat[ny][nx]) {
          cnt++;
        }
      }
    }
  }
  if (cnt == 1) {
    answer += 1;
  }
  else if (cnt == 2) {
    answer += 10;
  }
  else if (cnt == 3) {
    answer += 100;
  }
  else if (cnt == 4) {
    answer += 1000;
  }
}

int main() {
  
  cin >> N;
  int a, b, c, d, e;
  
  for (int i = 0; i < N*N; i++) {
    cin >> a >> b >> c >> d >> e;
    v[a].push_back(b);
    v[a].push_back(c);
    v[a].push_back(d);
    v[a].push_back(e);
    position(a,b,c,d,e);
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      solve(j, i);
    }
  }
  
  cout << answer;
  
  
}
