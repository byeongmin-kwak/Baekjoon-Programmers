#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<int> v;
int answer = 0;

int main() {
  
  cin >> T;
  
  while(T--) {
    answer = 0;
    v.clear();

    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++) {
      cin >> tmp;
      v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
      
    
    for (int i = 0; i < v.size()-2; i+=2) {
      answer = max(answer, v[i+2]-v[i]);
    }
    
    if (N % 2 == 0) {
      for (int i = N-1; i >= 2; i-=2) {
        answer = max(answer, v[i]-v[i-2]);
      }
    }
    else {
      for (int i = N-2; i >= 2; i-=2) {
        answer = max(answer, v[i]-v[i-2]);
      }
    }
    
    answer = max(answer, v[N-1]-v[N-2]);
    answer = max(answer, v[1]-v[0]);


    cout << answer << endl;
    
  }
}
