#include <bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) > abs(b)) {
            return true;
        }
        else if (abs(a) == abs(b)) {
            if (a > b) {
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
};


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, cmp>pq;

    
    int N;
    cin >> N;
    
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x == 0) {
            if (!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else {
                cout << 0 << '\n';
            }

        }
        else {
            pq.push(x);
        }
    }
    
}
