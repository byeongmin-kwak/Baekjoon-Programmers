#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int N;
int arr[100000];
pair<int, int> ans;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void solve() {
  int left = 0, right = N - 1;
  int minSum = INT_MAX;

  while (left < right) {
    int sum = arr[left] + arr[right];

    if (abs(sum) < minSum) {
      minSum = abs(sum);
      ans = {arr[left], arr[right]};
    }

    if (sum < 0) {
      left++;
    } else {
      right--;
    }
  }
}

int main() {
  
  input();
  
  solve();
  
  cout << ans.first << ' ' << ans.second;
}
