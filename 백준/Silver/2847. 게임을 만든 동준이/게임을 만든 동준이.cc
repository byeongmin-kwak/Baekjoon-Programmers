#include <bits/stdc++.h>

using namespace std;


int main() {

    int N;
    cin >> N;
    
    int arr[100];
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int ans = 0;
    for (int i = N - 2; i >= 0; i--) {
        if (arr[i] >= arr[i+1]) {
            ans += arr[i] - arr[i+1] + 1;
            arr[i] = arr[i] - (arr[i] - arr[i+1] + 1);
        }
    }
    
    cout << ans;
    
}

