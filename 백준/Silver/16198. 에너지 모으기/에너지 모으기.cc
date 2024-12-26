#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans;
vector<int> originalV;

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int W;
    cin >> W;
    originalV.push_back(W);
  }
}

void solve(vector<int>& v, int sum) {
  if (v.size() == 2) {
    ans = max(sum, ans);
    return;
    
  }
  for (int i = 1; i < v.size()-1; i++) {
    vector<int> copy = v;
    copy.erase(copy.begin() + i);
    solve(copy, sum + v[i-1] * v[i+1]);
    
  }
}

int main() {
  
  input();
  
  solve(originalV, 0);
  
  cout << ans;
  
}