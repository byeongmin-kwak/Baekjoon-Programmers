#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int a, b;
    cin >> a >> b;
    
    int m;
    cin >> m;
    
    int temp = 0;
    stack<int> st;
    
    int n;
    for (int i = 0; i < m; i++) {
        cin >> n;
        st.push(n);
    }
    for (int i = 0; i < m; i++) {
        temp += pow(a, i) * st.top();
        st.pop();
    }
    
    
    while (true) {
        if (temp / b == 0) {
            st.push(temp % b);
            break;
        }
        else {
            st.push(temp % b);
            temp /= b;
        }
    }
    
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    
    return 0;
}

