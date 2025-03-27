#include <iostream>
#include <queue>

using namespace std;

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  priority_queue<int, vector<int>, greater<int>> pq;
  
  int N;
  cin >> N;
  
  int x;
  for (int i = 0; i < N; i++) {
    cin >> x;
    
    if (x == 0) {
      if (pq.size() > 0) {
        cout << pq.top() << '\n';;
        pq.pop();
      } else {
        cout << 0 << '\n';;
      }
    } else {
      pq.push(x);
    }
  }
}
