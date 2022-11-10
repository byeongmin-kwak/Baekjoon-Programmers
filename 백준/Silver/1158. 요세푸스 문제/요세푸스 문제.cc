#include <bits/stdc++.h>

using namespace std;

int main() {
    
    
    int N, K;
    cin >> N >> K;
    
    queue<int> que1, que2;
    for (int i = 1; i <= N; i++) {
        que1.push(i);
    }
    
    while (!que1.empty()) {
        for (int i = 0; i < K - 1; i++) {
            que1.push(que1.front());
            que1.pop();
        }
        
        que2.push(que1.front());
        que1.pop();
    }
    cout << '<';
    int size = que2.size();
    for (int i = 0; i < size -1; i++) {
        cout << que2.front() << ", ";
        que2.pop();
    }
    cout << que2.front();
    cout << '>';
    
    return 0;
}