#include <bits/stdc++.h>

using namespace std;

int main() {
  	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;

    string s;
    while(n--) {
        cin >> s;
        int check = 1;
        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                cnt++;
            }
            else {
                cnt--;
                if (cnt < 0) {
                    cout << "NO" << '\n';
                    check = 0;
                    break;
                }
            }
        }
        if (check == 1) {
            if (cnt == 0) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }
}