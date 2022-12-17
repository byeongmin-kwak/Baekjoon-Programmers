#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int N;
    cin >> N;
    
    priority_queue<int, vector<int>, greater<int>> pqu;
    
    int num;
    for (int i = 0 ; i < N; i++) {
        cin >> num;
        if (num == 0) {
            if (pqu.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pqu.top() << '\n';
                pqu.pop();
            }
        }
        else {
            pqu.push(num);
        }
    }
    
    
}

