#include <iostream>
#include <vector>

using namespace std;

int n, tmp, ans = 0;
vector<pair<int ,int>> tree[10001];


void input() {
  cin >> n;
  
  int a, b, c;
  for (int i = 0; i < n-1; i++) {
    cin >> a >> b >> c;
    
    tree[a].push_back({b,c});
    tree[b].push_back({a,c});
  }
}

void dfs(int current, int previous, int length) {
  if (length > ans) {
    ans = length;
    tmp = current;
  }
  
  for (int i = 0; i < tree[current].size(); i++) {
    pair<int, int> next = tree[current][i];
    if (next.first == previous) {
      continue;
    }
    dfs(next.first, current, length + next.second);
  }
}

int main() {
  
  input();
  
  dfs(1, 0, 0);
  dfs(tmp, 0, 0);
  
  cout << ans;
}
