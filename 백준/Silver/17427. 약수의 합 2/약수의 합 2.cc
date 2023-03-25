#include <bits/stdc++.h>

using namespace std;

long long ans = 0;

int main() {
    
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        ans += i * (N/i);
    }
    
    cout << ans << endl;
}
