#include <iostream>

using namespace std;

bool arr[31];

int main() {
  
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    arr[n] = true;
  }
  
  int cnt = 0;
  for (int i = 1; i < 31; i++) {
    if (!arr[i]) {
      cout << i << endl;
      cnt++;
      if (cnt >= 2) break;
    }
  }
}
