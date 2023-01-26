#include <bits/stdc++.h>

using namespace std;
    
int arr[16][2], N, ans[17];

void dp() {
    int deadline;
    for (int i = N; i >= 0; i--) {
        deadline = i + arr[i][0];
        if (deadline > N + 1) {
            ans[i] = ans[i+1];
        }
        else {
            ans[i] = max(ans[i+1], ans[deadline] + arr[i][1]);
        }
    }
}

int main() {
    
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    
    dp();
    cout << ans[1];
    
}
