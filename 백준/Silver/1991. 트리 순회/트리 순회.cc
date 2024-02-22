#include <iostream>

using namespace std;

int N;
char tree[26][2];
string ans;

void input() {
  cin >> N;
  
  char root;
  for (int i = 0; i < N; i++) {
    cin >> root;
    for (int j = 0; j < 2; j++) {
      cin >> tree[root-65][j];
    }
  }
}

void solve1(char node) {
  ans += node;
  
  for (int i = 0; i < 2; i++) {
    if (tree[node-65][i] != '.') {
      solve1(tree[node-65][i]);
    }
  }
}

void solve2(char node) {
  if (tree[node-65][0] != '.') {
    solve2(tree[node-65][0]);
  }
  ans += node;
  if (tree[node-65][1] != '.') {
    solve2(tree[node-65][1]);
  }
}

void solve3(char node) {
  for (int i = 0; i < 2; i++) {
    if (tree[node-65][i] != '.') {
      solve3(tree[node-65][i]);
    }
  }
  ans += node;

}

int main() {
  
  input();
    
  solve1('A');
  cout << ans << endl;
  
  ans = "";
  solve2('A');
  cout << ans << endl;

  ans = "";
  solve3('A');
  cout << ans << endl;

}
