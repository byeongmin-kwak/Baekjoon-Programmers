#include <iostream>

using namespace std;

int N, arr[12], operation[4], MAX = -1000000000, MIN = 1000000000;

void input() {
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < 4; i++) {
    cin >> operation[i];
  }
}

void dfs(int sum, int depth) {
  if (depth == N) {
    MAX = max(MAX, sum);
    MIN = min(MIN, sum);
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (operation[i] > 0) {
      operation[i]--;
      if (i == 0) {
        dfs(sum+arr[depth], depth+1);
      }
      else if (i == 1) {
        dfs(sum-arr[depth], depth+1);
      }
      else if (i == 2) {
        dfs(sum*arr[depth], depth+1);
      }
      else {
        dfs(sum/arr[depth], depth+1);
      }
      operation[i]++;
    }
  }
}

int main() {
  
  input();
  
  dfs(arr[0], 1);
  
  cout << MAX << endl << MIN;
  
}
