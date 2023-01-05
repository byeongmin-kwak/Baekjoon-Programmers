#include <bits/stdc++.h>

using namespace std;

int arr[8], temp[8];
int N;
bool visited[8];
int ans = 0;

void dfs(int depth) {
    if (depth == N) {
        int num = 0;
        for (int i = 0; i < N-1; i++) {
            num += abs(temp[i]-temp[i+1]);
        }
        ans = max(ans, num);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i] == true) {
            continue;
        }
        visited[i] = true;
        temp[depth] = arr[i];
        dfs(depth+1);
        visited[i] = false;
    }
}

int main() {

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    dfs(0);
    
    cout << ans << endl;
}
