#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    if (n == 1 or n == 2) {
        return 1; // 코드1
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int fibonacci(int n) {
    long long f[40];
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2]; // 코드2
    }
    return f[n];
}

int main() {

    int n;
    cin >> n;

    cout << fibonacci(n) << " " << n - 2;
}