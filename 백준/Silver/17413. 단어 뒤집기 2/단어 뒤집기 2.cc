#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s, temp;
    
    getline(cin, s);
  
    stack<char> st;
    
    bool check = true;
    for (int i = 0 ; i < s.size(); i++) {
        if (s[i] == '<') {
            check = false;
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
            temp += s[i];
        }
        else if (s[i] == '>') {
            check = true;
            temp += s[i];
            cout << temp;
            temp.clear();
        }
        else {
            if (s[i] == ' ') {
                if (check == false) {
                    temp += s[i];
                }
                else {
                    while (!st.empty()) {
                        cout << st.top();
                        st.pop();
                    }
                    cout << ' ';
                }
            }
            else {
                if (check == true) {
                    st.push(s[i]);
                }
                else {
                    temp += s[i];
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
