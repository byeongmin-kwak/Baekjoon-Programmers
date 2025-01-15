#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board(10, vector<int>(10));
bool domino[10][10];
int dy[2] = {0, 1};
int dx[2] = {1, 0};
bool flag;

bool check(int y, int x, int u) {
  
  // 행 체크
  for (int i = 1; i < 10; i++) {
    if (board[y][i] == u) {
      return false;
    }
  }
  
  // 열 체크
  for (int i = 1; i < 10; i++) {
    if (board[i][x] == u) {
      return false;
    }
  }

  // 3x3 정사각형 체크
  int tmpY = (y - 1) / 3 * 3 + 1;
  int tmpX = (x - 1) / 3 * 3 + 1;
  for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
          if (board[tmpY + i][tmpX + j] == u) return false;
      }
  }
  
  return true;
}

void dfs(int cnt) {
  if (flag) return;
  if (cnt >= 36) {
    flag = true;
    return;
  }
  
  // 좌표 선택
  for (int y = 1; y < 10; y++) {
    for (int x = 1; x < 10; x++) {
      if (board[y][x] != 0) continue;
      
      for (int k = 0; k < 2; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        
        if (ny >= 1 && ny <= 9 && nx >= 1 && nx <= 9) {
          if (board[ny][nx] != 0) continue;
          
          // 도미노 선택
          for (int i = 1; i < 10; i++) {
            for (int j = i+1; j < 10; j++) {
              if (domino[i][j]) continue;
              
              if (check(y, x, i) && check(ny, nx, j)) {
                board[y][x] = i;
                board[ny][nx] = j;
                domino[i][j] = true;
                
                dfs(cnt+1);
                if (flag) return;
                board[y][x] = 0;
                board[ny][nx] = 0;
                domino[i][j] = false;
              }
              
              if (check(y, x, j) && check(ny, nx, i)) {
                board[y][x] = j;
                board[ny][nx] = i;
                domino[i][j] = true;
                
                dfs(cnt+1);
                if (flag) return;
                board[y][x] = 0;
                board[ny][nx] = 0;
                domino[i][j] = false;
              }
            }
          }
        }
      }
      if (board[y][x] == 0) return;
    }
  }
  return;
}

int main() {
  
  int T = 0;
  while (true) {
    T++;
    int N;
    cin >> N;
    if (N == 0) {
      break;
    }
    
    // 초기 도미노 세팅
    int U, V;
    string LU, LV;
    for (int i = 0; i < N; i++) {
      cin >> U >> LU >> V >> LV;
      if (U < V) {
        domino[U][V] = true;
      }
      else {
        domino[V][U] = true;
      }
      int y = (int)LU[0] - 64;
      int x = LU[1] - '0';
      board[y][x] = U;
      
      y = (int)LV[0] - 64;
      x = LV[1] - '0';
      board[y][x] = V;
    }
    
    // 초기 숫자 세팅
    for (int i = 1; i < 10; i++) {
      string yx;
      cin >> yx;
      int y = (int)yx[0] - 64;
      int x = yx[1] - '0';
      board[y][x] = i;
    }
    
    dfs(N);
    
    // 정답 출력
    cout << "Puzzle " << T << endl;

    for (int i = 1; i < 10; i++) {
      for (int j = 1; j < 10; j++) {
        cout << board[i][j];
      }
      cout << endl;
    }
    
    // 초기화
    board = vector<vector<int>>(10, vector<int>(10)); // 보드 초기화
    for (int i = 1; i < 10; i++) {
      for (int j = i+1; j < 10; j++) {
        domino[i][j] = false; // 도미노 초기화
      }
    }
    flag = false; // 플래그 초기화
  }
}
