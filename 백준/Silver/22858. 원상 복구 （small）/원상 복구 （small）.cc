#include <iostream>

using namespace std;

int N, K;
int S[100000];
int D[100000];

int main() {
  
  cin >> N >> K;
  
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> D[i];
  }
  
  
  while(K--) {
    
    int* tmp = new int[N];
    
    for (int i = 0; i < N; i++) {
      tmp[D[i]-1] = S[i];
    }
    
    for (int i = 0; i< N; i++) {
      S[i] = tmp[i];
    }
    delete [] tmp;
  }
  
  for (int i = 0; i < N; i++) {
    cout << S[i] << ' ';
  }
  
}
