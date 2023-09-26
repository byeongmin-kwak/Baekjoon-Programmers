#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, M;
int arr[100][100];
bool outSideAir[100][100];
set<pair<int,int>> cheese;
int answer = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int,int>> disappear;

void setOutsideAir(int x, int y) {
  queue<pair<int,int>> que;
  que.push({x, y});
  
  while (!que.empty()) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();
    
    for (int i = 0 ; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      
      if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
        if (arr[ny][nx] == 0 && !outSideAir[ny][nx]) {
          outSideAir[ny][nx] = true;
          que.push({nx,ny});
        }
      }
    }
  }
}

int main() {
  
  // input
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 1) {
        cheese.insert({j,i});
      }
    }
  }
  
  // 초기 외부공기 구분
  for (int i = 0; i < N; i++) {
    setOutsideAir(0, i);
    setOutsideAir(M-1, i);
  }
  for (int i = 0; i < M; i++) {
    setOutsideAir(i, 0);
    setOutsideAir(i, N-1);
  }
  

  
  // 전체 치즈에 대한 검사 반복
  while(cheese.size() != 0) {
    answer++;
    // 치즈가 외부 공기랑 접촉하는지 검사
    for (auto elem : cheese) {
      int x = elem.first;
      int y = elem.second;
      int cnt = 0;
      
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (outSideAir[ny][nx]) {
          cnt++;
        }
      }
      
      // 사라질 치즈 큐에 넣기
      if (cnt >= 2){
        disappear.push({x,y});
      }
    }
    
    // 사라질 치즈 0으로 변경 및 외부공기 확장
    while(!disappear.empty()) {
      int x = disappear.front().first;
      int y = disappear.front().second;
      disappear.pop();
      
      arr[y][x] = 0;
      outSideAir[y][x] = true;
      setOutsideAir(x, y);
      cheese.erase({x, y});
    }
  }
  cout << answer;
}
