#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[10000];
int ans;

void input() {
  
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  
  cin >> M;
}

bool check(int maxValue) {
  
  int sum = 0;
  for (int i = 0; i < N; i++) {
    if (arr[i] <= maxValue) {
      sum += arr[i];
    }
    else {
      sum += maxValue;
    }
  }
  
  return sum <= M;
}

int main() {
  
  input();
  
  int left = 1;
  int right = 0;
  
  for (int i = 0; i < N; i++) {
    right = max(right, arr[i]);
  }
  
  while(left <= right) {
  
    int mid = (left+right) / 2;
    
    if (check(mid)) {
      ans = mid;
      left = mid+1;
    }
    else {
      right = mid-1;
    }
  }
  
  cout << ans;
}
