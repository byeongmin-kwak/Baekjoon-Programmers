#include <bits/stdc++.h>

using namespace std;

int N, M;
int* arr = new int[N];
int* temp = new int[N];
bool* visited = new bool[N];

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << temp[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            continue;
        }
        visited[i] = true;
        temp[depth] = arr[i];
        dfs(depth+1);
        visited[i] = false;
    }
}


int main() {
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    
    sort(arr, arr+N);
    
    dfs(0);
    
    
}

