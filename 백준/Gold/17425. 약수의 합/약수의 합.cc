#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

long long arr[MAX] = {0,};
long long dp[MAX] = {0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; i * j < MAX; j++) {
            arr[i*j] += i;
        }
    }
    
    for (int i = 1; i <= MAX; i++) {
        dp[i] = dp[i-1] + arr[i];
    }
    
    int T;
    cin >> T;
    
    while(T--) {
        int N;
        cin >> N;
        
        cout << dp[N] << '\n';
    }
}
