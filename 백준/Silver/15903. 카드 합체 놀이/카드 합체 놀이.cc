#include <bits/stdc++.h>

using namespace std;

long long n, m;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
    
    
    cin >> n >> m;
    
    long long num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        pq.push(num);
    }
    
    long long a, b, c;
    for (int i = 0; i < m; i++) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        c = a + b;
        pq.push(c);
        pq.push(c);
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += pq.top();
        pq.pop();
    }
    
    cout << ans;
}
