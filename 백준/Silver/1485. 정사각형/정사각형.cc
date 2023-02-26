#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> v;

int main() {

    int T;
    
    cin >> T;
    
    while(T--) {
        
        int x, y;
        
        for (int i = 0; i < 4; i++) {
            cin >> x >> y;
            v.push_back(make_pair(x, y));
        }
        
        sort(v.begin(),v.end());
        
        int a, b, c, d, e, f;
        
        a = pow(v[0].first - v[1].first, 2) + pow(v[0].second - v[1].second, 2);
        b = pow(v[0].first - v[2].first, 2) + pow(v[0].second - v[2].second, 2);
        c = pow(v[1].first - v[3].first, 2) + pow(v[1].second - v[3].second, 2);
        d = pow(v[2].first - v[3].first, 2) + pow(v[2].second - v[3].second, 2);
        e = pow(v[1].first - v[2].first, 2) + pow(v[1].second - v[2].second, 2);
        f = pow(v[0].first - v[3].first, 2) + pow(v[0].second - v[3].second, 2);
        
        if (a == b && a == c && a == d && a+b == e && b+d == f) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
        
        v.clear();
        
    }
    
}
