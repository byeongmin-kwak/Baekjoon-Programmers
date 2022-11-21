#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, S;
    cin >> N >> S;

    int num, result;
    cin >> num;
    result = abs(S - num);

    for (int i = 0; i < N - 1; i++) {
        cin >> num;
        result = gcd(result, abs(S - num));
    }

    cout << result << endl;
}


