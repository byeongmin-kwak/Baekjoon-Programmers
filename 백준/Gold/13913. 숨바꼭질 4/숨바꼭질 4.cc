    #include <bits/stdc++.h>

    using namespace std;

    int N, K;
    bool visited[1000000];
    pair<int,string> p[1000000];

    void bfs(int N, int K) {
        if (N == K) {
            return;
        }
        visited[N] = true;

        queue<int> que;
        int a = N - 1;
        int b = N + 1;
        int c = N * 2;

        if (N > K) {
            que.push(a);
            p[a] = {1,"-1"};
            visited[a] = true;
        }
        else {
            if (a >= 0) {
                que.push(a);
                p[a] = {1,"-1"};
                visited[a] = true;
            }
            
            if (b <= 100000) {
                que.push(b);
                p[b] = {1,"+1"};
                visited[b] = true;
            }
            
            if (c <= 100000) {
                que.push(c);
                p[c] = {1,"*2"};
                visited[c] = true;
            }
        }

        while(!que.empty()) {
            int tmp = que.front();
            que.pop();
            if (tmp == K) {
                break;
            }
            int a = tmp - 1;
            int b = tmp + 1;
            int c = tmp * 2;
            
            if (tmp > K) {
                if (!visited[a]) {
                    que.push(a);
                    p[a] = {p[tmp].first+1,"-1"};
                    visited[a] = true;
                }
            }
            else {
                if (a >= 0 && !visited[a]) {
                    que.push(a);
                    p[a] = {p[tmp].first+1,"-1"};
                    visited[a] = true;
                }
                
                if (!visited[b] && b <= 100000) {
                    que.push(b);
                    p[b] = {p[tmp].first+1,"+1"};
                    visited[b] = true;
                }
                
                if (!visited[c] && c <= 100000) {
                    que.push(c);
                    p[c] = {p[tmp].first+1,"*2"};
                    visited[c] = true;
                }
            }
        }
    }

    int main() {
        cin >> N >> K;
        
        bfs(N, K);
        
        stack<int> st;
        int ans = K;
        st.push(ans);
        
        while(ans != N) {
            if (p[ans].second == "-1") {
                ans += 1;
            }
            else if (p[ans].second == "+1") {
                ans -= 1;
            }
            else {
                ans /= 2;
            }
            st.push(ans);
            
        }
        cout << p[K].first << '\n';
        
        while(!st.empty()) {
            cout << st.top() << ' ';
            st.pop();
        }
        
        
    }
