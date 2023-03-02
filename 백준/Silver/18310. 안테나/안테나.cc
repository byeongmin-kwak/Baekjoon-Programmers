#include <bits/stdc++.h>

using namespace std;

int main() {
 
    int N;
    cin >> N;
    
    vector<int> v;
    
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }
    
    sort(v.begin(), v.end());
    
    cout << v[(N-1)/2];
    
}
