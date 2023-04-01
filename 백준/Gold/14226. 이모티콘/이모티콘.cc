#include <bits/stdc++.h>

using namespace std;

int S;
int ans;
bool visited[2000][2000]; // screen, clipboard


void bfs() {
    
    queue<pair<int,pair<int,int>>> que; // screen, time, clipboard
    que.push({1,{0,0}});
    visited[1][0] = true;
    
    while(!que.empty()) {
        int screen = que.front().first;
        int time = que.front().second.first;
        int clipboard = que.front().second.second;
        que.pop();
        
        if (screen == S) {
            ans = time;
            break;
        }
        
        // 붙여넣기
        if (clipboard != 0 && screen+clipboard <= 2000) {
            que.push({screen+clipboard,{time+1,clipboard}});
        }
        
        // 복사
        if (!visited[screen][screen]) {
            visited[screen][screen] = true;
            que.push({screen,{time+1,screen}});
        }
        
        // 삭제
        if (!visited[screen-1][clipboard] && screen-1 > 0) {
            visited[screen-1][clipboard] = true;
            que.push({screen-1,{time+1,clipboard}});
        }
        
    }
    
}


int main() {
    
    cin >> S;
    
    bfs();
    
    cout << ans;
    
}
