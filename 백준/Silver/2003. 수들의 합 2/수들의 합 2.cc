#include <bits/stdc++.h>

using namespace std;

int arr[10000];
int N, M;
int ans = 0;

void solve() {
    
    int a = 0, b = 0, sum = arr[0];
    
    while (true) {
        if (a >= N || b >= N) {
            break;
        }
        
        if (sum == M) {
            ans++;
            sum -= arr[a];
            a++;
            b++;
            sum += arr[b];
        }
        else if (sum < M) {
            b++;
            sum += arr[b];
        }
        else if (sum > M) {
            sum -= arr[a];
            a++;
        }
    }
    
    cout << ans << '\n';
    
}

int main() {
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    solve();
    
}
