#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x;
vector<int> v;
int ans = 0;

void input() {
  cin >> n;
  
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    v.push_back(tmp);
  }
  cin >> x;
}

int main() {
  
  input();
  
  sort(v.begin(), v.end());
  
  int a = 0, b = n - 1;
  while (true) {
    if (a >= b) {
      break;
    }
    if (v[a] + v[b] == x) {
      ans++;
      for (int i = b-1; i > a; i--) {
        if (v[i] == v[b]) {
          ans++;
        }
        else {
          break;
        }
      }
      a++;
    }
    else if (v[a] + v[b] < x) {
      a++;
    }
    else {
      b--;
    }
  }
  
  cout << ans;
  
}
