#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[500][500], ans;
bool visit[500][500];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, - 1 };

void dfs(int x, int y, int sum, int depth) {
    if (depth == 4) {
        if (ans < sum) {
            ans = sum;
        }
        return;
    }
    sum += arr[x][y];

    visit[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || n <= nx || ny < 0 || m <= ny || visit[nx][ny])
            continue;
        dfs(nx, ny, sum, depth + 1);
    }
    visit[x][y] = false;
    return;
}

void exceptionCase(int x, int y) {
    int flag = 0, sum = arr[x][y];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || n <= nx || ny < 0 || m < ny) {
            continue;
        }
        sum += arr[nx][ny];
        flag++;
    }

    if (flag < 3) {
        return;
    }
    else if (flag == 3) {
        if (ans < sum) {
            ans = sum;
        }
    }
    else if (flag == 4) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (ans < sum - arr[nx][ny]) {
                ans = sum - arr[nx][ny];
            }
        }
    }
    return;
}



int main() {

    cin >> n >> m;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(i, j, 0, 0);
            exceptionCase(i, j);
        }
    }

    cout << ans;


}