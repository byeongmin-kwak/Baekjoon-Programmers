#include <iostream>

using namespace std;

int N, M, K;
int ans = 0;

void input() {
  cin >> N >> M >> K;
}

int main() {
  
  input();
  
  int tmp = min(N/2, M);
  
  int ans = min(tmp, (N+M-K) / 3);
  
  cout << ans;
}
