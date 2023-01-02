#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int N;
    cin >> N;
    
    if (N < 10) {
        cout << N << endl;
        return 0;
    }
    
    int cnt = 2, check = 100, ans = 9;
    while (true) {
        if (N < check) {
            break;
        }
        else {
            ans += (check - check / 10) * cnt;
        }
        cnt += 1;
        check *= 10;
    }
    check /= 10;
        
    ans += (N - check + 1) * cnt;
    
    cout << ans << endl;
    
}

