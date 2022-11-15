#include <bits/stdc++.h>

using namespace std;


int main() {
        
    string s;
    
    while (getline(cin, s)) {
        int arr[4] = {};

        for (int i = 0; i < s.length(); i++) {
            
            if (s[i] >= 'a' and s[i] <= 'z') {
                arr[0]++;
            }
            else if (s[i] >= 'A' and s[i] <= 'Z') {
                arr[1]++;
            }
            else if (s[i] >= '0' and s[i] <= '9') {
                arr[2]++;
            }
            else if (s[i] == ' ') {
                arr[3]++;
            }

        }

        for (int i = 0 ; i < 4; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;

    }

    
    return 0;
}



