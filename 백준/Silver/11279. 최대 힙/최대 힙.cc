#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    priority_queue<int> pq;
    
    int N;
    cin >> N;
    
    for (int i = 0 ; i < N; i++) {
        int num;
        cin >> num;
        
        if (num != 0) {
            pq.push(num);
        }
        else {
            if (pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}
