#include <iostream>

using namespace std;

bool block[500][500];
int H, W;

int main() {
  cin >> H >> W;
  
  int answer = 0;
  
  int tmp;
  for (int i = 0; i < W; i++) {
    cin >> tmp;
    for (int j = H-1; j > H-1-tmp; j--) {
      block[j][i] = true;
    }
  }
  
  for (int i = 0; i < H; i++) {
    int flag = -1;
    for (int j = 0; j < W; j++) {
      if (block[i][j]) {
        if (flag != -1) {
          answer += j - flag - 1;
        }
        flag = j;
      }
    }
  }
  
  cout << answer;
}
