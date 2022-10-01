#include <bits/stdc++.h>

using namespace std;


int main() {
    
    string s;
    cin >> s;
    
    sort(s.begin(), s.end());
    
    string* ans = new string[s.length()];
    
    if (s.length() % 2 == 0) {
        int index = 0;
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] == s[i+1]) {
                ans[index] = s[i];
                ans[s.length() - 1 - index] = s[i];
                index++;
            }
            else {
                cout << "I'm Sorry Hansoo";
                index = 0;
                break;
            }
        }
        if (index != 0) {
            for (int i = 0; i < s.length(); i++) {
                cout << ans[i];
            }
        }
    }
    else {
        int check = 0;
        int index = 0;
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] == s[i+1]) {
                ans[index] = s[i];
                ans[s.length() - 1 - index] = s[i];
                index++;
                if (index == s.length()) {
                    index++;
                }
            }
            else {
                check++;
                if (check >= 2) {
                    break;
                }
                ans[s.length() / 2] = s[i];
                i--;
            }
        }
        if (check >= 2) {
            cout << "I'm Sorry Hansoo";
        }
        else {
            for (int i = 0; i < s.length(); i++) {
                cout << ans[i];
            }
        }
        
        
    }
    

    
    delete[] ans;
}

