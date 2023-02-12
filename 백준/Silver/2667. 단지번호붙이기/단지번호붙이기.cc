#include <bits/stdc++.h>

using namespace std;
 
int N, arr[25][25];
int direction[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
bool visited[25][25];
int cnt = 0;
vector<int> v;

void dfs(int x, int y) {
    cnt++;
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + direction[i][0];
        int ny = y + direction[i][1];
        
        if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
            if (visited[nx][ny] == false && arr[nx][ny] == 1) {
                dfs(nx, ny);
            }
        }
    }
}




int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < N; j++) {
            arr[i][j] = input[j] - '0';
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == false && arr[i][j] == 1) {
                dfs(i,j);
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }

    cout << v.size() << '\n';
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }


}
