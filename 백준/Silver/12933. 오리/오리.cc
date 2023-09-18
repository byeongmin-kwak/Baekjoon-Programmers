#include <iostream>
#include <map>

using namespace std;

map<char, int> duck;

int main() {
  int ans = 0;
  
  duck['q'] = 0;
  duck['u'] = 0;
  duck['a'] = 0;
  duck['c'] = 0;
  duck['k'] = 0;
  
  string s;
  cin >> s;
  
  for (char elem : s) {
    if (elem == 'q') {
      duck['q']++;
      duck['u']++;
      if (duck['q'] > ans) {
        ans = duck['q'];
      }
    }
    else if (elem == 'u') {
      if (duck['u'] <= 0) {
        ans = -1;
        break;
      }
      duck['u']--;
      duck['a']++;
    }
    else if (elem == 'a') {
      if (duck['a'] <= 0) {
        ans = -1;
        break;
      }
      duck['a']--;
      duck['c']++;
    }
    else if (elem == 'c') {
      if (duck['c'] <= 0) {
        ans = -1;
        break;
      }
      duck['c']--;
      duck['k']++;
    }
    else {
      if (duck['k'] <= 0) {
        ans = -1;
        break;
      }
      duck['k']--;
      duck['q']--;
    }
  }
  
  for (auto iter : duck) {
    if (iter.second != 0) {
      ans = -1;
      break;
    }
  }
  
  cout << ans;

}
