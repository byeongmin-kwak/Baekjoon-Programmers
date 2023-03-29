#include <bits/stdc++.h>

using namespace std;

vector<int> v[20001];
bool visited[20001];
int check[20001];
string ans = "YES";

void bfs(int start) {
    queue<int> que;
    que.push(start);
    check[start] = 1;
    visited[start] = true;

    while(!que.empty()) {
        int tmp = que.front();
        que.pop();
        
        if (check[tmp] == 1) {
            for (auto elem : v[tmp]) {
                if (check[elem] == 1) {
                    ans = "NO";
                    break;
                }
                else {
                    if (!visited[elem]) {
                        visited[elem] = true;
                        check[elem] = 2;
                        que.push(elem);
                    }
                }
            }
        }
        else {
            for (auto elem : v[tmp]) {
                if (check[elem] == 2) {
                    ans = "NO";
                    break;
                }
                else {
                    if (!visited[elem]) {
                        visited[elem] = true;
                        check[elem] = 1;
                        que.push(elem);
                    }
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        
        for (int i = 0; i < 20001; i++) {
            v[i].clear();
            visited[i] = false;
            check[i] = 0;
        }
        ans = "YES";

        int V, E;
        cin >> V >> E;

        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        for (int i = 1; i <= V; i++) {
            if (!visited[i])
                bfs(i);
        }
        
        cout << ans << '\n';
    }
}
