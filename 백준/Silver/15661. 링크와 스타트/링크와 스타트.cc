#include <bits/stdc++.h>

using namespace std;
    
int arr[21][21], N, ans = 10000000;
bool check[21];

void dfs(int st) {
    if (st >= N) {
        int st = 0, lin = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (check[i] && check[j]) {
                    st += arr[i][j];
                }
                else if (!check[i] && !check[j]) {
                    lin += arr[i][j];
                }
            }
        }
        if (ans > abs(st-lin))
            ans = abs(st-lin);
    }
    for (int i = st; i <= N; i++) {
        if (!check[i]) {
            check[i] = true;
            dfs(i);
            check[i] = false;
        }
    }
}

int main() {

    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    
    dfs(1);
    cout << ans << endl;
    
    
    
}
