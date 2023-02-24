#include <bits/stdc++.h>

using namespace std;

int N, M;
bool arr[1001][1001];
bool check[1001];
int result = 0;

void dfs(int v) {
    
    check[v] = true;
    
    for (int i = 1; i <= N; i++) {
        if (arr[v][i] && !check[i]) {
            check[i] = true;
            dfs(i);
        }
    }
}

int main() {
    cin >> N >> M;
    
    int u, v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        arr[u][v] = true;
        arr[v][u] = true;
    }
    
    for (int i = 1; i <= N; i++) {
        if (!check[i]) {
            result++;
            dfs(i);
        }
    }
    
    cout << result << '\n';
}
