#include <bits/stdc++.h>

using namespace std;

int N, K, ans[100001];

void bfs() {
    
    ans[N] = 0;
    
    if (N == K) {
        return;
    }
    
    queue<int> que;
    
    int a = N - 1;
    int b = N + 1;
    int c = N * 2;
    
    if (c <= 100000) {
        que.push(c);
        ans[c] = 0;
    }
    
    if (a >= 0 && a <= 100000) {
        que.push(a);
        ans[a] = 1;
    }
    if (b <= 100000 && ans[b] > ans[N] + 1) {
        que.push(b);
        ans[b] = 1;
    }

    
        
    while(!que.empty()) {
        int position = que.front();
        que.pop();
        
        if (position == K)
            break;
            
        int a = position - 1;
        int b = position + 1;
        int c = position * 2;
        
        if (c <= 100000 && ans[c] > ans[position]) {
            que.push(c);
            ans[c] = ans[position];
        }
        if (a >= 0 && a <= 100000 && ans[a] > ans[position] + 1) {
            que.push(a);
            ans[a] = ans[position] + 1;
        }
        if (b <= 100000 && ans[b] > ans[position] + 1) {
            que.push(b);
            ans[b] = ans[position] + 1;
    
        }
    }
}

int main() {
    
    cin >> N >> K;
    
    for (int i = 0; i <= 100000; i++) {
        ans[i] = 100000;
    }
    
    bfs();
    
    cout << ans[K];
}
