#include <bits/stdc++.h>

using namespace std;
 
vector<int> arr[100001];
vector<int> visited(100001, 0);
queue<int> que;
int cnt = 0;

void bfs(int start) {
    visited[start] = ++cnt;
    que.push(start);
    
    while(!que.empty()) {
        int n = que.front();
        que.pop();
        
        for (auto& edge : arr[n]) {
            if (visited[edge])
                continue;
            que.push(edge);
            visited[edge] = ++cnt;
        }
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
        sort(arr[i].begin(), arr[i].end());
    }
    
    bfs(R);
    
    for (int i = 1; i <= N; i++) {
        cout << visited[i] << '\n';
    }
}
