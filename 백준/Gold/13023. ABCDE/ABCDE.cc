#include <bits/stdc++.h>

using namespace std;

vector<int> v[2001];
int N, M;
bool visited[2001];
bool check;

void dfs(int depth, int node) {
    if (depth == 4) {
        check = true;
        cout << 1 << '\n';
        exit(0);
    }
    for (auto i : v[node]) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(depth+1, i);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    
    for (int i = 0; i < N; i++) {
        visited[i] = true;
        dfs(0,i);
        visited[i] = false;
    }
    
    if (!check)
        cout << 0 << '\n';
    

    
    
}
