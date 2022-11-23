#include <bits/stdc++.h>

using namespace std;

int main() {


    string s;
    cin >> s;

    int n;
    cin >> n;

    int result = 0;

    for (int i = 0; i < s.length(); i++) {

        if (s[s.length() - i - 1] >= '0' and s[s.length() - i - 1] <= '9') {
            result += (pow(n, i) * (int(s[s.length() - i - 1]) - '0'));
        }
        else {
            result += (pow(n, i) * (int(s[s.length() - i - 1]) - 55));
        }

    }

    cout << result << endl;
}

