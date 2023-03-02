#include <bits/stdc++.h>

using namespace std;

int arr[1000000];

int main() {
 
    int T;
    cin >> T;
        
    while(T--) {
        long long ans = 0;

        int N;
        cin >> N;
        
        int maxValue = 0;
        
        for (int i = 0; i < N; i++) {
            cin >> arr[i];

        }
        
        
        for (int i = N-1; i >= 0; i--) {
            maxValue = max(maxValue, arr[i]);
            ans += maxValue-arr[i];
        }
        
        cout << ans << '\n';
        
        
    }
    
}
