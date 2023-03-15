#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    else {
        return a.second > b.second;
    }
}

int main() {
    int n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int d, t;
        cin >> d >> t;
        
        v.push_back({d,t});
    }
    
    sort(v.begin(), v.end(), compare);
    
    for (int i = 0; i < n-1; i++) {
        if (v[i].second - v[i].first + 1 <= v[i+1].second) {
            v[i+1].second = v[i].second - v[i].first;
        }
    }
    
    cout << v[n-1].second - v[n-1].first << endl;
    
}
