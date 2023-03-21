#include <bits/stdc++.h>

using namespace std;

int arr[105][105];
int N;
bool check =  false;

void dfs(int x, int y) {
    if (x == N-1 && y == N-1) {
        check = true;
        cout << "HaruHaru" << endl;
        exit(0);
    }
    else if (x >= N || y >= N) {
        return;
    }
    else {
        if (arr[y][x] != 0) {
            dfs(x+arr[y][x],y);
            dfs(x,y+arr[y][x]);
        }
    }
}

int main() {
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    
    dfs(0,0);
    
    if (!check) {
        cout << "Hing" << endl;
    }
    
}
