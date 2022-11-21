#include <bits/stdc++.h>

using namespace std;

int main() {

    string s, result;
    
    cin >> s;
    
    int cnt = 0, temp = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            temp += pow(2, cnt);
        }
        if (cnt == 2) {
            result += to_string(temp);
            temp = 0;
            cnt = -1;
        }
        cnt++;
    }
    
    if (cnt != 0) {
        result += to_string(temp);

    }
    
    for (int i = result.length() - 1; i >= 0; i--) {
        cout << result[i];
    }
    
}


