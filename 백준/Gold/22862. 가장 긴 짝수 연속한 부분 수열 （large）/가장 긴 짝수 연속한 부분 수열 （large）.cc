#include <iostream>
#include <queue>

using namespace std;

int N, K;
int arr[1000000];
int ans = 0;

int main() {
  
  cin >> N >> K;
  
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  
  int start = N-1, end = N-1, evenCnt = 0;
  
  //처음 등장하는 짝수 찾기
  for (int i = 0; i < N; i++) {
    if (arr[i] % 2 == 0) {
      start = i;
      end = i;
      evenCnt = 1;
      ans++;
      break;
    }
  }
  
  queue<int> odd;
  
  //첫 짝수부터 탐색 시작
  for (int i = start+1; i < N; i++) {
    //현재 홀수일 때
    if (arr[i] % 2 != 0) {
      odd.push(i);
      if (odd.size() > K) {
        int oddIdx = odd.front();
        odd.pop();
        
        //제거했던 홀수 중 맨 앞 홀수를 다시 원상복구하고 start를 그 홀수 뒤로 다시 조정
        for (int idx = start; idx < N; idx++) {
          if (arr[idx] % 2 == 0) {
            if (idx < oddIdx) {
              evenCnt--;
            }
            else {
              start = idx;
              break;
            }
          }
        }
      }
      
    }
    //현재 짝수일 때
    else {
      evenCnt++;
    }
    
    if (evenCnt > ans) {
      ans = evenCnt;
    }
  }
  
  cout << ans;
}
