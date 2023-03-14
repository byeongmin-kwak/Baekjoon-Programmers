#include <bits/stdc++.h>

using namespace std;

int N;
int arr[50];

int main() {
    cin >> N;
    
    int maxNum = 0;
    int ans = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] != 0) {
            ans++;
        }
    }
        
    for (int i = 0; i < N; i++) {
        int tmp = 0;
        while (arr[i] > 1) {
            if (arr[i] % 2 == 0) {
                tmp++;
                arr[i] = arr[i] / 2;
            }
            else {
                ans++;
                arr[i]--;
            }
            maxNum = max(maxNum, tmp);
        }
    }
    
    cout << ans + maxNum << endl;
    
}
