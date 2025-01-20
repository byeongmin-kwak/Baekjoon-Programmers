#include <iostream>

using namespace std;

int N;
int arr[100000][3];
int maxValue, minValue;
int maxDP[3], minDP[3];

void input() {
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> arr[i][j];
    }
  }
}

void solve() {
  
  // 첫 번째 행 초기화
  for (int i = 0; i < 3; i++) {
    maxDP[i] = arr[0][i];
    minDP[i] = arr[0][i];
  }
  
  // 두 번째 행부터 시작
  for (int i = 1; i < N; i++) {
    int prevMaxDP[3], prevMinDP[3];
    
    // 이전 값 저장
    for (int j = 0; j < 3; j++) {
      prevMaxDP[j] = maxDP[j];
      prevMinDP[j] = minDP[j];
    }
    
    for (int j = 0; j < 3; j++) {
      if (j == 0) {
        maxDP[j] = arr[i][j] + max(prevMaxDP[0], prevMaxDP[1]);
        minDP[j] = arr[i][j] + min(prevMinDP[0], prevMinDP[1]);
      }
      if (j == 1) {
        maxDP[j] = arr[i][j] + max(prevMaxDP[0], max(prevMaxDP[1], prevMaxDP[2]));
        minDP[j] = arr[i][j] + min(prevMinDP[0], min(prevMinDP[1], prevMinDP[2]));
      }
      if (j == 2) {
        maxDP[j] = arr[i][j] + max(prevMaxDP[1], prevMaxDP[2]);
        minDP[j] = arr[i][j] + min(prevMinDP[1], prevMinDP[2]);
      }
    }
  }
  
  maxValue = max(maxDP[0], max(maxDP[1], maxDP[2]));
  minValue = min(minDP[0], min(minDP[1], minDP[2]));
}

int main() {
  
  input();
  
  solve();
  
  cout << maxValue << ' ' << minValue;
  
  
}
