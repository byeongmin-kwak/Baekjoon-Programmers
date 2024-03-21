#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
pair<int, int> ans;
vector<int> v;

void input() {
  cin >> N;
  
  int tmp;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    v.push_back(tmp);
  }
}

int main() {
  
  input();
  
  sort(v.begin(), v.end());
  
  int left = 0, right = N-1;
  int result = 2000000000;
  while (left < right) {
    if (abs(v[left] + v[right]) < abs(result)) {
      result = v[left] + v[right];
      ans.first = v[left];
      ans.second = v[right];
      if (v[left] + v[right] > 0) {
        right--;
      }
      else {
        left++;
      }
    }
    else if (v[left] + v[right] > 0) {
      right--;
    }
    else {
      left++;
    }
  }
  
  cout << ans.first << ' ' << ans.second;
}
