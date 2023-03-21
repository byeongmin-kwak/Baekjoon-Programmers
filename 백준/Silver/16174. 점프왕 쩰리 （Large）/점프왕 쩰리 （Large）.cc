#include <bits/stdc++.h>

using namespace std;

int arr[200][200];
int N;
bool check[200][200];
queue<pair<int, int>> que;

void dfs(int x, int y) {
    if (x == N-1 && y == N-1) {
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

void bfs() {
    if (arr[0][0] != 0 && arr[0][0] < N) {
        que.push({0,arr[0][0]});
        que.push({arr[0][0],0});
        
    }
    
    while(!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        if (x == N-1 && y == N-1) {
            cout << "HaruHaru" << endl;
            exit(0);
            
        }
        if (arr[y][x] != 0) {
            if (x+arr[y][x] < N && check[y][x+arr[y][x]] == false) {
                que.push({y,x+arr[y][x]});
                check[y][x+arr[y][x]] = true;
            }
            if (y+arr[y][x] < N && check[y+arr[y][x]][x] == false) {
                que.push({y+arr[y][x], x});
                check[y+arr[y][x]][x] = true;
            }
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
    
    bfs();
    
    cout << "Hing" << endl;
    
}
