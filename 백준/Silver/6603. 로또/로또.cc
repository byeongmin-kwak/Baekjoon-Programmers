#include <bits/stdc++.h>

using namespace std;

int arr[13], n, ans[6];
bool check[13];


void dfs(int depth, int index) {
    if (depth == 6) {
        for (int i = 0; i < 6; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = index; i < n; i++) {
        if (check[i] == true)
            continue;

        ans[depth] = arr[i];
        check[i] = true;
        dfs(depth+1, i);
        check[i] = false;
    }
}


int main() {
    
    while (true) {
        cin >> n;
        if (n == 0)
            break;
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        dfs(0,0);
        cout << '\n';
    }
    
}
