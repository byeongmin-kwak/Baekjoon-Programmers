#include <bits/stdc++.h>

using namespace std;

int N, K, ans[100001];
bool visited[100001];

void bfs() {
    
    if (N == K) {
        return;
    }
    
    queue<int> que;
    
    int a = N - 1;
    int b = N + 1;
    int c = N * 2;
    
    if (a >= 0 && a < 100000) {
        que.push(a);
        ans[a] = 1;
        visited[a] = true;
    }
    if (b >= 0 && b < 100000) {
        que.push(b);
        ans[b] = 1;
        visited[b] = true;
    }
    if (c > 0 && c < 100000) {
        que.push(c);
        ans[c] = 1;
        visited[c] = true;
    }
    
        
    while(!que.empty()) {
        int position = que.front();
        que.pop();
        
        int a = position - 1;
        int b = position + 1;
        int c = position * 2;
        
        if (a >= 0 && a <= 100000 && visited[a] == false) {
            que.push(a);
            ans[a] = ans[position] + 1;
            visited[a] = true;
        }
        if (b >= 0 && b <= 100000 && visited[b] == false) {
            que.push(b);
            ans[b] = ans[position] + 1;
            visited[b] = true;
        }
        if (c > 0 && c <= 100000 && visited[c] == false) {
            que.push(c);
            ans[c] = ans[position] + 1;
            visited[c] = true;
        }
    
        if (position == K) {
            break;
        }
    }
}

int main() {
    
    cin >> N >> K;
    
    bfs();
    
    cout << ans[K];
}
