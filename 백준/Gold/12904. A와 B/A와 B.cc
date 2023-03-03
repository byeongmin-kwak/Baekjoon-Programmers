#include <bits/stdc++.h>

using namespace std;

int main() {

    string S, T;
    cin >> S >> T;
    
    while(true) {
        if (S.size() == T.size()) {
            if (S == T) {
                cout << 1 << '\n';
                break;
            }
            else {
                cout << 0 << '\n';
                break;
            }
        }
        else {
            if (T[T.size() - 1] == 'A') {
                T.pop_back();
            }
            else {
                T.pop_back();
                reverse(T.begin(), T.end());
            }
        }
    }
    
    
}

