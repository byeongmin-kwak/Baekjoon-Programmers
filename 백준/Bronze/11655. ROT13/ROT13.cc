#include <bits/stdc++.h>

using namespace std;


int main() {

    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {

        if (s[i] >= 'a' and s[i] <= 'z') {
            if (int(s[i])+13 > int('z')) {
                cout << char(int((s[i])+13) % int('z') +'a' - 1);
            }
            else {
                cout << char(int(s[i])+13);
            }
        }
        else if (s[i] >= 'A' and s[i] <= 'Z') {
            if (int(s[i])+13 > int('Z')) {
                cout << char(int((s[i])+13) % int('Z') +'A' - 1);
            }
            else {
                cout << char(int(s[i])+13);
            }

        }
        else {
            cout << s[i];
        }

    }

    
    return 0;
}