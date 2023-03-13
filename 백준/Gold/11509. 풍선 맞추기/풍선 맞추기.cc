#include <bits/stdc++.h>

using namespace std;

int N, num, maxNum, ans;
int arr[1000003];

int main() {
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> num;
        maxNum = max(num, maxNum);
        arr[num]++;
        if (arr[num+1] > 0)
            arr[num+1]--;
    }
    
    for (int i = 1; i <= maxNum; i++) {
        ans += arr[i];
    }
    
    cout << ans << '\n';
    
}
