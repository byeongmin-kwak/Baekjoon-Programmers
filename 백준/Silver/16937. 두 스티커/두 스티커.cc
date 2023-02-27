#include <bits/stdc++.h>

using namespace std;

int H, W, N;
pair<pair<int, int>,int> sticker[200];
bool visited[100];
pair<int, int> stk[2];
int ans;


void check() {
    if (stk[0].second + stk[1].second <= W && max(stk[0].first,stk[1].first) <= H) {
        ans = max(ans, stk[0].first*stk[0].second + stk[1].first*stk[1].second);
    }
    if (stk[0].second + stk[1].second <= H && max(stk[0].first,stk[1].first) <= W) {
        ans = max(ans, stk[0].first*stk[0].second + stk[1].first*stk[1].second);
    }

}

void solve(int idx, int size, int cnt) {
    if (cnt == 2) {
        check();
        return;
    }
    for (int i = idx; i < size; i++) {
        if (visited[sticker[i].second]) {
            continue;
        }
        visited[sticker[i].second] = true;
        int R = sticker[i].first.first;
        int C = sticker[i].first.second;
        stk[cnt] = {R,C};
        solve(idx+1, size, cnt+1);
        visited[sticker[i].second] = false;
        
    }
}


int main() {
    
    cin >> H >> W >> N;
    
    int idx = 0;
    for (int i = 0; i < N; i++) {
        int R, C;
        cin >> R >> C;
        sticker[idx++] = {{R,C},i};
        if (R != C) {
            sticker[idx++] = {{C,R},i};
        }
    }
    solve(0, idx, 0);
    cout << ans << '\n';
}
