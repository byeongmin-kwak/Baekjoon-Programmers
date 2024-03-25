#include <iostream>

using namespace std;

int N;
int primeArr[4000001];
int ans = 0;

void input() {
  cin >> N;
}

void eratos() {
  for (int i = 2; i <= N; i++) {
    primeArr[i] = true;
  }
  
  for (int i = 2; i * i <= N; i++) {
    if (primeArr[i]) {
      for (int j = i * i; j <= N; j += i) {
        primeArr[j] = false;
      }
    }
  }
}

int main() {
  
  input();
  
  eratos();
  
  int left = 2, right = 2, sum = 2;
  
  bool check = true;
  while (check && left < N && right < N) {
    if (sum == N) {
      ans++;
      sum -= left;
      for (int i = left+1; i <= N; i++) {
        if (primeArr[i]) {
          left = i;
          break;
        }
        if (i == N) {
          check = false;
        }
      }
    }
    else if (sum < N) {
      for (int i = right+1; i <= N; i++) {
        if (primeArr[i]) {
          right = i;
          break;
        }
        if (i == N) {
          check = false;
        }
      }
      sum += right;
    }
    else {
      sum -= left;
      for (int i = left+1; i <= N; i++) {
        if (primeArr[i]) {
          left = i;
          break;
        }
        if (i == N) {
          check = false;
        }
      }
    }
  }
  
  if (primeArr[N]) {
    ans++;
  }
  
  cout << ans;
  
}
