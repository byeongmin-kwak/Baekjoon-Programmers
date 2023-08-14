#include <iostream>

using namespace std;

int arr[1001][1001];

int main() {
    
    int N, n;
    cin >> N >> n;
    
    int x = 0;
    int y = 0;
    
    int direction = 1;
    
    pair<int, int> answer;
    
    for (int i = N * N; i >= 1; i--) {
        arr[y][x] = i;
        if (i == n) {
            answer.first = y+1;
            answer.second = x+1;
        }
        
        if (direction == 1) {
            if (y+1 < N && arr[y+1][x] == 0) {
                y++;
            }
            else {
                direction = 2;
                x++;
            }
        }
        else if (direction == 2) {
            if (x+1 < N && arr[y][x+1] == 0) {
                x++;
            }
            else {
                direction = 3;
                y--;
            }
        }
        else if (direction == 3) {
            if (y-1 >= 0 && arr[y-1][x] == 0) {
                y--;
            }
            else {
                direction = 4;
                x--;
            }
        }
        else {
            if (x-1 >= 0 && arr[y][x-1] == 0) {
                x--;
            }
            else {
                direction = 1;
                y++;
            }
        }
        
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    
    cout << answer.first << ' ' << answer.second;
    
    
}
