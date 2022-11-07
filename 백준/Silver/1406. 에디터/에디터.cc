#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;
    
    int M;
    cin >> M;
    
    char command, p;
    
    stack<char> st1, st2;
    for (int i = 0; i < s.length(); i++) {
        st1.push(s[i]);
    }
    
    while (M--) {
        cin >> command;
        
        switch (command) {
            case 'L':
                if (!st1.empty()) {
                    st2.push(st1.top());
                    st1.pop();
                }
                break;
            case 'D':
                if (!st2.empty()) {
                    st1.push(st2.top());
                    st2.pop();
                }
                break;
            case 'B':
                if (!st1.empty()) {
                    st1.pop();
                }
                break;
            case 'P':
                cin >> p;
                st1.push(p);
                break;
        }
    }
    
    while (!st2.empty()) {
        st1.push(st2.top());
        st2.pop();
    }
    
    while (!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
    }
    
    while (!st2.empty()) {
        cout << st2.top();
        st2.pop();
    }
    
    return 0;
}




