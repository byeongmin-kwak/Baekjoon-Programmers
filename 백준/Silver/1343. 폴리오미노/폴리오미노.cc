#include <bits/stdc++.h>

using namespace std;

int main() {
 
    string s;
    cin >> s;
    
    string ans;
    
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'X') {
            cnt++;
        }
        else {
            if (cnt % 2 != 0) {
                cout << -1 << '\n';
                return 0;
            }
            else {
                for (int j = 0; j < cnt / 4; j++) {
                    ans += "AAAA";
                }
                for (int j = 0; j < (cnt % 4) / 2; j++) {
                    ans += "BB";
                }
                cnt = 0;
            }
            ans += ".";
        }
    }
    
    if (cnt % 2 != 0) {
        cout << -1 << '\n';
        return 0;
    }
    else {
        for (int j = 0; j < cnt / 4; j++) {
            ans += "AAAA";
        }
        for (int j = 0; j < (cnt % 4) / 2; j++) {
            ans += "BB";
        }
    }
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << '\n';
    
}
