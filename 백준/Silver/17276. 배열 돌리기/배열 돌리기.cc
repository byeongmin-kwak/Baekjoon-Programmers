#include <iostream>

using namespace std;

int arr[500][500];
int tmp[8];
int T, n, d;
int dx[8] = {1, 1, 0, 0, -1, -1, 0, 0};
int dy[8] = {0 ,0, 1, 1, 0, 0, -1, -1};

int dx2[8] = {0, 0, 1, 1, 0 ,0, -1, -1};
int dy2[8] = {1, 1, 0, 0, -1, -1, 0, 0};


void solve(int x, int y, int cnt) {
    int nx = x;
    int ny = y;
    
    if (d > 0) {
        for (int i = 0; i < 8; i++) {
            tmp[i] = arr[ny][nx];
            nx += dx[i] * cnt;
            ny += dy[i] * cnt;
        }
    }
    else {
        for (int i = 0; i < 8; i++) {
            tmp[i] = arr[ny][nx];
            nx += dx2[i] * cnt;
            ny += dy2[i] * cnt;
        }
    }
    
    
    for (int i = 0; i < 8; i++) {
        nx = x;
        ny = y;
        
        if (d > 0) {
            for (int j = i; j < i + d/45; j++) {
                nx += dx[j%8] * cnt;
                ny += dy[j%8] * cnt;
            }
            x += dx[i] * cnt;
            y += dy[i] * cnt;
        }
        else {
            for (int j = i; j < i + d/(-45); j++) {
                nx += dx2[j%8] * cnt;
                ny += dy2[j%8] * cnt;
            }
            x += dx2[i] * cnt;
            y += dy2[i] * cnt;
        }
        
        arr[ny][nx] = tmp[i];
    }
}

int main() {
    
    cin >> T;
    
    while (T--) {
        cin >> n >> d;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        
        for (int i = 1; i <= n/2; i++) {
            solve(n/2-i, n/2-i, i);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }
}
