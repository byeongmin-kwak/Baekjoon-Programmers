#include <iostream>
#include <vector>

using namespace std;

int N, S[21];
bool check[20*100000+1];

void input() {
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
}

void dfs(int sum, int index) {
  if (index > N) return;
  check[sum] = true;
  dfs(sum+S[index], index+1);
  dfs(sum, index+1);
}

int main() {
  
  input();
  
  dfs(0, 0);
    
  for (int i = 1; i < 20*100000+1; i++) {
    if (!check[i]) {
      cout << i;
      break;
    }
  }
}
