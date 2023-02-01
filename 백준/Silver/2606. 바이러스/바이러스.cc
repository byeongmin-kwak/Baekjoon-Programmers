#include <bits/stdc++.h>

using namespace std;
 
vector<int> arr[101];
vector<bool> visited(101);
queue<int> que;
int cnt = 0;

void bfs(int start) {
    visited[start] = true;
    que.push(start);
    
    while(!que.empty()) {
        int n = que.front();
        que.pop();
        
        for (auto& edge : arr[n]) {
            if (visited[edge])
                continue;
            que.push(edge);
            visited[edge] = true;
            cnt++;
        }
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
    
    bfs(1);
    
    cout << cnt << endl;
    
}
