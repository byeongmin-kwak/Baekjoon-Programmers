#include <bits/stdc++.h>

using namespace std;
 
vector<int> arr[101];
vector<bool> visited(101);
int cnt = -1;

void dfs(int start) {
    visited[start] = true;
    cnt++;
    
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
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    dfs(1);
    
    cout << cnt << endl;
    
}
