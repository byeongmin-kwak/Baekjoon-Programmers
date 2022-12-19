#include <bits/stdc++.h>

using namespace std;

int arr[200000][2];

int main() {
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    
    sort(v.begin(), v.end());
    
    pq.push(v[0].second);
    
    for (int i = 1; i < N; i++) {
        if (pq.top() <= v[i].first) {
            pq.pop();
            pq.push(v[i].second);
        }
        else {
            pq.push(v[i].second);
        }
    }
    
    cout << pq.size() << endl;
}
