#include <bits/stdc++.h>

using namespace std;

int chessboard[301][301];
int ans[301][301];
bool visited[301][301];

void bfs(pair<int,int> current, pair<int,int> target, int maxBoard) {
    if (current == target) {
        return;
    }
    
    queue<pair<int,int>> que;
    
    pair<int,int> a = make_pair(current.first-1, current.second-2);
    pair<int,int> b = make_pair(current.first-2, current.second-1);
    pair<int,int> c = make_pair(current.first-2, current.second+1);
    pair<int,int> d = make_pair(current.first-1, current.second+2);
    pair<int,int> e = make_pair(current.first+1, current.second+2);
    pair<int,int> f = make_pair(current.first+2, current.second+1);
    pair<int,int> g = make_pair(current.first+2, current.second-1);
    pair<int,int> h = make_pair(current.first+1, current.second-2);
    
    if (a.first >= 0 && a.second >= 0 && a.first < maxBoard && a.second < maxBoard) {
        que.push(a);
        visited[a.first][a.second] = true;
        ans[a.first][a.second] = 1;
    }
    if (b.first >= 0 && b.second >= 0 && b.first < maxBoard && b.second < maxBoard) {
        que.push(b);
        visited[b.first][b.second] = true;
        ans[b.first][b.second] = 1;
    }
    if (c.first >= 0 && c.second >= 0 && c.first < maxBoard && c.second < maxBoard) {
        que.push(c);
        visited[c.first][c.second] = true;
        ans[c.first][c.second] = 1;
    }
    if (d.first >= 0 && d.second >= 0 && d.first < maxBoard && d.second < maxBoard) {
        que.push(d);
        visited[d.first][d.second] = true;
        ans[d.first][d.second] = 1;
    }
    if (e.first >= 0 && e.second >= 0 && e.first < maxBoard && e.second < maxBoard) {
        que.push(e);
        visited[e.first][e.second] = true;
        ans[e.first][e.second] = 1;
    }
    if (f.first >= 0 && f.second >= 0 && f.first < maxBoard && f.second < maxBoard) {
        que.push(f);
        visited[f.first][f.second] = true;
        ans[f.first][f.second] = 1;
    }
    if (g.first >= 0 && g.second >= 0 && g.first < maxBoard && g.second < maxBoard) {
        que.push(g);
        visited[g.first][g.second] = true;
        ans[g.first][g.second] = 1;
    }
    if (h.first >= 0 && h.second >= 0 && h.first < maxBoard && h.second < maxBoard) {
        que.push(h);
        visited[h.first][h.second] = true;
        ans[h.first][h.second] = 1;
    }
    

    
    while(!que.empty()) {
        pair<int,int> temp = que.front();
        que.pop();
        
        if(temp == target) {
            break;
        }
        
        pair<int,int> a = make_pair(temp.first-1, temp.second-2);
        pair<int,int> b = make_pair(temp.first-2, temp.second-1);
        pair<int,int> c = make_pair(temp.first-2, temp.second+1);
        pair<int,int> d = make_pair(temp.first-1, temp.second+2);
        pair<int,int> e = make_pair(temp.first+1, temp.second+2);
        pair<int,int> f = make_pair(temp.first+2, temp.second+1);
        pair<int,int> g = make_pair(temp.first+2, temp.second-1);
        pair<int,int> h = make_pair(temp.first+1, temp.second-2);
        
        if (a.first >= 0 && a.second >= 0 && a.first < maxBoard && a.second < maxBoard && visited[a.first][a.second] == false) {
            que.push(a);
            visited[a.first][a.second] = true;
            ans[a.first][a.second] = ans[temp.first][temp.second] + 1;
        }
        if (b.first >= 0 && b.second >= 0 && b.first < maxBoard && b.second < maxBoard && visited[b.first][b.second] == false) {
            que.push(b);
            visited[b.first][b.second] = true;
            ans[b.first][b.second] = ans[temp.first][temp.second] + 1;
        }
        if (c.first >= 0 && c.second >= 0 && c.first < maxBoard && c.second < maxBoard && visited[c.first][c.second] == false) {
            que.push(c);
            visited[c.first][c.second] = true;
            ans[c.first][c.second] = ans[temp.first][temp.second] + 1;
        }
        if (d.first >= 0 && d.second >= 0 && d.first < maxBoard && d.second < maxBoard && visited[d.first][d.second] == false) {
            que.push(d);
            visited[d.first][d.second] = true;
            ans[d.first][d.second] = ans[temp.first][temp.second] + 1;
        }
        if (e.first >= 0 && e.second >= 0 && e.first < maxBoard && e.second < maxBoard && visited[e.first][e.second] == false) {
            que.push(e);
            visited[e.first][e.second] = true;
            ans[e.first][e.second] = ans[temp.first][temp.second] + 1;
        }
        if (f.first >= 0 && f.second >= 0 && f.first < maxBoard && f.second < maxBoard && visited[f.first][f.second] == false) {
            que.push(f);
            visited[f.first][f.second] = true;
            ans[f.first][f.second] = ans[temp.first][temp.second] + 1;
        }
        if (g.first >= 0 && g.second >= 0 && g.first < maxBoard && g.second < maxBoard && visited[g.first][g.second] == false) {
            que.push(g);
            visited[g.first][g.second] = true;
            ans[g.first][g.second] = ans[temp.first][temp.second] + 1;
        }
        if (h.first >= 0 && h.second >= 0 && h.first < maxBoard && h.second < maxBoard && visited[h.first][h.second] == false) {
            que.push(h);
            visited[h.first][h.second] = true;
            ans[h.first][h.second] = ans[temp.first][temp.second] + 1;
        }
        

    }
    
}

int main() {
        
    int T;
    cin >> T;
    
    while(T--) {
        
        int maxBoard;
        cin >> maxBoard;
        
        for (int i = 0; i <= maxBoard; i++) {
            for (int j = 0; j <= maxBoard; j++) {
                ans[i][j] = 0;
                visited[i][j] = false;
            }
        }
        
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        pair<int,int> current;
        pair<int,int> target;
        
        current = make_pair(a, b);
        target = make_pair(c, d);
        
        bfs(current, target, maxBoard);
        
        cout << ans[target.first][target.second] << '\n';
        
        
        
    }
    
}
