#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    int n;

    while(b != 0){
        n = a % b;
        a = b;
        b = n;
    }
    
    return a;
}

int lcm(int a, int b){
    return a*b / gcd(a, b);
}

int main(){
        
    int T, M, N, x, y;
    cin >> T;
    
    
    while (T--) {
        cin >> M >> N >> x >> y;

        int end = lcm(M, N);
        int ans = -1;

        for (int i = x; i <= end; i+=M) {
            
            if (i % N == 0 && N == y) {
                ans = i;
                break;
            }
            
            else if (i % N == y) {
                ans = i;
                break;
            }
        }
        cout << ans << '\n';
    }
    
}

