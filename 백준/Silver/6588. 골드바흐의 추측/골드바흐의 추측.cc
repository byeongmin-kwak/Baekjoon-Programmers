#include <bits/stdc++.h>

using namespace std;

bool arr[1000001];

void SET() {
    arr[0] = true;
    arr[1] = true;
    
    for (int i = 2; i * i < 1000001; i++) {
        if (arr[i] == true)
            continue;
        for (int j = i * i; j < 1000001; j+=i) {
            arr[j] = true;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base :: sync_with_stdio(false);
    
    int n;
    bool check = false;
    SET();
    
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        check = false;

        for (int i = 3; i < n; i+=2) {
            if (!arr[i] && !arr[n-i]) {
                cout << n << " = " << i << " + " << n-i << '\n';
                check = true;
                break;
            }
        }
        if (!check) {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }
    
    return 0;
}
