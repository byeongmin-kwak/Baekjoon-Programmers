#include <bits/stdc++.h>

using namespace std;


int main() {
        
    string s;
    cin >> s;
    
    queue<char> que;
    stack<char> st;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' and s[i] <= 'Z') {
            cout << s[i];
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            if (st.empty()) {
                st.push(s[i]);
            }
            else {
                if (s[i] == '+' or s[i] == '-') {
                    while (!st.empty() and st.top() != '(') {
                        cout << st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
                else {
                    while (!st.empty() and (st.top() == '*' or st.top() == '/')) {
                        cout << st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
    }
    
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
        
    cout << endl;
    
    return 0;
}