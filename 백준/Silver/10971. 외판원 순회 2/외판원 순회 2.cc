#include <bits/stdc++.h>

using namespace std;

bool check[11];
int n, ans = 10000000;
int v[10][10];

void go(int start, int index, int cnt, int sum) {
    if (cnt == n) {
        if (v[index][start] == 0)
            return;
        if (ans > (sum + v[index][start])) {
            ans = sum + v[index][start];
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (check[i] == true || v[index][i] == 0)
            continue;
        check[i] = true;
        go(start, i, cnt+1, sum+v[index][i]);
        check[i] = false;
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        check[i] = true;
        go(i, i, 1, 0);
        check[i] = false;
    }
    
    cout << ans << endl;
    
}
