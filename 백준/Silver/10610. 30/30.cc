#include <bits/stdc++.h>

using namespace std;


int main() {
    
    string s;
    cin >> s;
    
    sort(s.begin(), s.end(),greater<>());

    if (s[s.length() - 1] != '0') {
        cout << -1;
    }
    else {
        long long sum = 0;
        
        for (auto o : s) {
            sum += o - '0';
        }
        if (sum % 3 == 0) {
            cout << s;
        }
        else {
            cout << -1;
        }
    }
    
}
