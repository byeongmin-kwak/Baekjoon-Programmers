#include <iostream>

using namespace std;

int N;
int arr[100001][3];
bool visited[100001];
long long answer = 0;

int main() {
 
  cin >> N;

  int a, b, c;
  for (int i = 0; i < N; i++) {
    cin >> a >> b >> c;
    arr[a][0] = b;
    arr[a][1] = c;
    if (b != -1) {
      arr[b][2] = a;
    }
    if (c != -1) {
      arr[c][2] = a;
    }
  }
  
  int current = 1;
  int visitCnt = 0;
  
  while (true) {
//    cout << current << ' ' << visitCnt << endl;
    if (visitCnt == N) {
      if (visited[current]) {
        answer--;
      }
      break;
    }
    if (arr[current][0] != -1 && !visited[arr[current][0]]) {
      current = arr[current][0];
      answer++;
      continue;
    }
    else if (arr[current][1] != -1 && !visited[arr[current][1]]) {
      visited[current] = true;
      visitCnt++;
      current = arr[current][1];
      answer++;
    }
    else {
      if (current == 1) {
        break;
      }
      if (!visited[current]) {
        visited[current] = true;
        visitCnt++;
      }
      current = arr[current][2];
      answer++;
    }
  }
  
  cout << answer;
}
