#include <bits/stdc++.h>

using namespace std;

int arr[1000001];

int main() {
    int T;
    cin >> T;
    
    for (int i = 2; i <= 1000001; i++) {
        arr[i] = i;
    }

    for (int i = 2; i * i <= 1000001; i++) {
        if (arr[i] != 0) {
            for (int j = i * i; j <= 1000001; j += i) {
                arr[j] = 0;
            }
        }
    }
    
    
    int n, result = 0;;
    while (T--) {
        cin >> n;
        result = 0;
        
        for (int i = 2; i <= n / 2; i++) {
            if (arr[i] + arr[n-i] == n) {
                result++;
            }
        }
        cout << result << endl;
    }
}
