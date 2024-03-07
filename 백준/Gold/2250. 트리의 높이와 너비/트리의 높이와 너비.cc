#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, root;
int col = 0;
bool isRoot[10001];
pair<int, int> node[10001];
vector<int> rowAndCol[10001];
pair<int, int> ans = {0, 0};


void input() {
  cin >> N;
  
  int num;
  for (int i = 0; i < N; i++) {
    cin >> num;
    cin >> node[num].first >> node[num].second;
    
    if (node[num].first > 0) {
      isRoot[node[num].first] = true;
    }
    if (node[num].second > 0) {
      isRoot[node[num].second] = true;
    }
  }
}

void findRoot() {
  for (int i = 1; i <= N; i++) {
    if (!isRoot[i]) {
      root = i;
      return;
    }
  }
}

void inorder(int cur, int row) {
  if (cur == -1) return;
  
  inorder(node[cur].first, row+1);
  col++;
  rowAndCol[row].push_back(col);
  inorder(node[cur].second, row+1);
}

void solve() {
  for (int i = 1; i <= N; i++) {
    if (rowAndCol[i].size() == 0) break;
    
    int maxValue = *max_element(rowAndCol[i].begin(), rowAndCol[i].end());
    int minValue = *min_element(rowAndCol[i].begin(), rowAndCol[i].end());
    
    if ((maxValue-minValue+1) > ans.second) {
      ans.first = i;
      ans.second = maxValue-minValue+1;
    }
  }
}

int main() {

  input();
  
  findRoot();
  
  inorder(root, 1);
  
  solve();
  
  cout << ans.first << ' ' << ans.second;
    
}
