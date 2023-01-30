#include <bits/stdc++.h>

using namespace std;

int k, ans[10];
char inequality[10];
bool check1[10], check2[10];


void solve1(int index) {
    if (index == k+1) {
        for (int i = 0; i < k+1; i++) {
            cout << ans[i];
        }
        cout << endl;
        return;
    }
    int cnt = 0;
    for (int i = index; i < k; i++) {
        if (inequality[i] == '<') {
            cnt++;
        }
        else
            break;
    }
    for (int i = 9; i >= 0; i--) {
        if (check1[i] == true)
            continue;
        ans[index] = i-cnt;
        check1[i-cnt] = true;
        break;
    }
    solve1(index+1);
}

void solve2(int index) {
    if (index == k+1) {
        for (int i = 0; i < k+1; i++) {
            cout << ans[i];
        }
        cout << endl;
        return;
    }
    int cnt = 0;
    for (int i = index; i < k; i++) {
        if (inequality[i] == '>') {
            cnt++;
        }
        else
            break;
    }
    for (int i = 0; i <= 9; i++) {
        if (check2[i] == true)
            continue;
        ans[index] = i+cnt;
        check2[i+cnt] = true;
        break;
    }
    solve2(index+1);
}

int main() {
    
    cin >> k;
    
    for (int i = 0 ; i < k; i++) {
        cin >> inequality[i];
    }
    
    solve1(0);
    solve2(0);
    
}
