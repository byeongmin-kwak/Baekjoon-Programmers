#include <iostream>

using namespace std;

int N, S;
int arr[100000];
int ans = 1000000;

void input() {
  cin >> N >> S;
  
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
}

int main() {
  
  input();
  
  int left = 0, right = 0, sum = arr[0];
  while (right < N) {
    if (sum >= S) {
      if ((right - left + 1) < ans) {
        ans = right - left + 1;
      }
      
      if (left == right) {
        sum += arr[right];
        right++;
      }
      else {
        sum -= arr[left];
        left++;
      }
    }
    else {
      right++;
      sum += arr[right];
    }
  }
  
  if (ans == 1000000) {
    ans = 0;
  }
  
  cout << ans;
}
