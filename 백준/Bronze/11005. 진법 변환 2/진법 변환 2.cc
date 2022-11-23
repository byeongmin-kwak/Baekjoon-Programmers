#include <bits/stdc++.h>

using namespace std;

int main() {

    int N, B;
    cin >> N >> B;

    string s;
    int temp;
    while (true) {

        if (N / B == 0) {
            if (N % B < 10) {
                s += to_string(N % B);
            }
            else {
                temp = N % B + 55;
                s += (char)temp;
            }
            break;
        }
        else {
            if (N % B < 10) {
                s += to_string(N % B);
                N /= B;
            }
            else {
                temp = N % B + 55;
                s += (char)temp;
                N /= B;
            }
        }

    }
    
    reverse(s.begin(), s.end());
    cout << s << endl;

}

