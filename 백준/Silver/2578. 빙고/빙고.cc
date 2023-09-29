#include <iostream>

using namespace std;

int arr[5][5];
bool visited[5][5];


pair<int,int> find(int n) {
  
  int x, y;
  for (int i = 0 ; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (arr[i][j] == n) {
        x = j;
        y = i;
        visited[i][j] = true;
        return {x, y};
      }
    }
  }
  return {x, y};
}

int checkBingo(int x, int y) {
  int cnt = 0;
  
  int check = 0;
  for (int i = 0; i < 5; i++) {
    if (visited[y][i]) {
      check++;
    }
  }
  if (check == 5) {
    cnt++;
  }
  check = 0;
  for (int i = 0; i < 5; i++) {
    if (visited[i][x]) {
      check++;
    }
  }
  if (check == 5) {
    cnt++;
  }
  
  check = 0;
  if (x == y) {
    for (int i = 0; i < 5; i++) {
      if (visited[i][i]) {
        check++;
      }
    }
  }
  if (check == 5) {
    cnt++;
  }
  
  check = 0;
  if (x + y == 4) {
    for (int i = 0; i < 5; i++) {
      if (visited[i][4-i]) {
        check++;
      }
    }
  }
  if (check == 5) {
    cnt++;
  }
  
  return cnt;
}

int main() {
  int answer = 0;
  
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> arr[i][j];
    }
  }
  
  int n;
  int cnt = 0;
  for (int i = 1; i <= 25; i++) {
    cin >> n;
    pair<int, int> p;
    p = find(n);
    cnt += checkBingo(p.first, p.second);
    if (cnt >= 3) {
      answer = i;
      break;
    }
  }
  cout << answer;
  
}
