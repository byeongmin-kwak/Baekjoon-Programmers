#include <bits/stdc++.h>

using namespace std;

int arr[8], ans[8];
int N;
bool visited[8];

void dfs(int depth) {
    if (depth == N) {
        for (int i = 0; i < N; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i] == true) {
            continue;
        }
        visited[i] = true;
        ans[depth] = arr[i];
        dfs(depth+1);
        visited[i] = false;
    }
}

int main() {

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        arr[i] = i+1;
    }
    
    dfs(0);
    
}
