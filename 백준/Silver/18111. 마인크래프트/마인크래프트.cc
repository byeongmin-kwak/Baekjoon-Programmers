#include <bits/stdc++.h>

using namespace std;

int N, M, B;
int arr[500][500];
int T = 100000000, H = 0;

int main() {
    
    cin >> N >> M >> B;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int h = 0; h <= 256; h++) {
        int build = 0;
        int remove = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (h < arr[i][j]) {
                    remove += arr[i][j] - h;
                }
                else if (h > arr[i][j]) {
                    build += h - arr[i][j];
                }
            }
        }
        if (remove + B >= build) {
            if (remove * 2 + build <= T) {
                T = remove * 2 + build;
                H = h;
            }
        }
    }
    
    cout << T << ' ' << H;
    
    
}
