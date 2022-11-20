#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y)
{
    if (x % y == 0) return y;
    else return gcd(y, x % y);
}

long long arr[100];

int main() {
    
    int t, n;
    cin >> t;
    
    long long result;

    while(t--) {
        cin >> n;
        
        result = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i+1; j < n; j++) {
                result += gcd(arr[i], arr[j]);
            }
        }
        
        cout << result << endl;
    }
}
