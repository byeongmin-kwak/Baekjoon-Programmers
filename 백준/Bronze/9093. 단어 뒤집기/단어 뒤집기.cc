#include <bits/stdc++.h>

using namespace std;

int main() {
    

    int T;
    cin >> T;
    cin.ignore();
    string s;
    stack<char> st;
    
    
    while (T--) {
        getline(cin, s);
        s += ' ';
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                st.push(s[i]);
            }
            else {
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            }
        }
        cout << endl;
    }
    
    return 0;
}