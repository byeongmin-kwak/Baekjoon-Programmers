#include <bits/stdc++.h>

using namespace std;

int arr[1001];
int dp[1001];
vector<int> v;

int main() {

    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
    }
    
    int result = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        result = max(result, dp[i]);
    }
    
    cout << result << endl;
    
    int temp = result;
    for (int i = n; i > 0; i--) {
        if (dp[i] == temp) {
            v.push_back(arr[i]);
            temp--;
        }
    }
    
    for (int i = 0; i < result; i++) {
        cout << v.back() << ' ';
        v.pop_back();
    }
    
    
}
