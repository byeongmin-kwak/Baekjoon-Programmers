#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
long long arr[30];
int ans = 0;

void input() {
  cin >> N >> C;
  
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
}

void dfs(int start, int end, long long sum, int depth, int target, vector<long long>& part) {
  if (depth+1 > target) {
    part.push_back(sum);
    return;
  }
  for (int i = start; i <= end; i++) {
    dfs(i+1, end, sum+arr[i], depth+1, target, part);
  }
}

int main() {
  input();
  
  vector<long long> left;
  vector<long long> right;
  
  for (int i = 0; i <= (N+1)/2; i++) {
    dfs(0, N/2-1, 0, 0, i, left);
    dfs(N/2, N-1, 0, 0, i, right);
  }
  
  sort(left.begin(), left.end());
  sort(right.begin(), right.end());
  
  for (int i = 0; i < left.size(); i++) {
    ans += upper_bound(right.begin(), right.end(), C-left[i]) - right.begin();
  }
  
  cout << ans;
}
