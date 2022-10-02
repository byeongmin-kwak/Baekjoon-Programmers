#include <bits/stdc++.h>

using namespace std;

int arr[10000];
int n, k;
int arr2[10000];

int main() {
    
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    for (int i = 0; i < n - 1; i++) {
        arr2[i] = arr[i+1] - arr[i];
    }
    
    sort(arr2, arr2 + n - 1, greater<int>());
    
    
    int ans = 0;
    
    for (int i = k - 1; i < n - 1; i++) {
        ans += arr2[i];
    }
    
    cout << ans;
    
}




