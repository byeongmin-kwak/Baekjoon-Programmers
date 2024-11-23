#include <iostream>

using namespace std;

int main() {
  
  int T, N, M;
  
  cin >> T;
  
  while(T--) {
    cin >> N >> M;
    long long result = 1;
    int tmp = 1;
    for (int i = M; i > M-N; i--) {
      result *= i;
      result /= tmp;
      tmp++;
    }
    cout << result << endl;
  }
  
}
