#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;
long long ans = 0;

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    if (v[0] > 1) {
        ans += v[0] - 1;
        v[0] = 1;
    }
    
    for (int i = 1; i < N; i++) {
        if (v[i] > v[i-1]+1) {
            ans += v[i] - (v[i-1]+1);
            v[i] = v[i-1]+1;
        }
    }
    
    cout << ans << endl;
}
