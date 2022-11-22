#include <bits/stdc++.h>

using namespace std;

int main() {

    string arr[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    
    string s, result;
    cin >> s;
    
    if (s == "0") {
        cout << 0 << endl;
    }
    else {
        for (long long i = 0; i < s.length(); i++) {
            result += arr[s[i]-'0'];
            
        }
        
        
        int index = 0;
        
        while (true) {
            if (result[index] == '0') {
                index++;
            }
            else {
                break;
            }
        }
        
        for (long long i = index; i < result.length(); i++) {
            cout << result[i];
        }
        
        cout << endl;
    }
}


