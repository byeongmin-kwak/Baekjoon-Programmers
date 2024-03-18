#include <iostream>
#include <vector>

using namespace std;

int V;
int ans = 0;
int tmp;
vector<pair<int, int>> tree[100001];
bool visited[100001];

void input() {
  cin >> V;
  
  int n, tmp1, tmp2;
  for (int i = 0; i < V; i++) {
    cin >> n;
    while (true) {
      cin >> tmp1;
      if (tmp1 == -1) {
        break;
      }
      cin >> tmp2;
      
      tree[n].push_back({tmp1, tmp2});
    }
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
    dfs(next.first, current, length+next.second);
  }
}

int main() {
  
  input();
  
  dfs(1, 0, 0);
  dfs(tmp, 0, 0);
  
  cout << ans;
}
