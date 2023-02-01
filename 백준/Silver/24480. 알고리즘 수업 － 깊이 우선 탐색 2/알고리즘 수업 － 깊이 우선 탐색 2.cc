#include <bits/stdc++.h>

using namespace std;
 
vector<int> arr[100001];
vector<int> visited(100001, 0);
int cnt = 0;

void dfs(int start) {
    visited[start] = ++cnt;
    
    for (auto& edge : arr[start]) {
        if (visited[edge])
            continue;
        dfs(edge);
    }
}   

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, R;
    
    cin >> N >> M >> R;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        sort(arr[i].rbegin(), arr[i].rend());
    }
    
    dfs(R);
    
    for (int i = 1; i <= N; i++) {
        cout << visited[i] << '\n';
    }
}
