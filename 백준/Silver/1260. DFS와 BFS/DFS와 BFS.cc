#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int N, M, V;
int MAP[MAX][MAX];
bool visited[MAX];
queue<int> q;

void reset() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}
 
void DFS(int v) {
    visited[v] = true;
    cout << v << " ";
        
    for (int i = 1; i <= N; i++) {
        if (MAP[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}
 
void BFS(int v) {
    q.push(v);
    visited[v] = true;
    cout << v << " ";
 
    while (!q.empty()) {
        v = q.front();
        q.pop();
        
        for (int w = 1; w <= N; w++) {
            if (MAP[v][w] == 1 && visited[w] == 0) {
                q.push(w);
                visited[w] = true;
                cout << w << " ";
            }
        }
    }
}
 
int main() {
    cin >> N >> M >> V;
 
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        MAP[a][b] = 1;
        MAP[b][a] = 1;
    }
 
    reset();
    DFS(V);
    
    cout << '\n';
    
    reset();
    BFS(V);
 
    return 0;
}
