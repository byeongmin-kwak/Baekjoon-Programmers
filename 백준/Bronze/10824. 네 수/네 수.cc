#include <bits/stdc++.h>

using namespace std;


int main() {

    
    string s;
    getline(cin, s);
    
    string arr[4];
    int check = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            arr[check] += s[i];
        }
        else {
            check++;
        }
    }
    
    string a, b;
    
    a = arr[0] + arr[1];
    b = arr[2] + arr[3];
    
    cout << stol(a) + stol(b) << endl;
    
    
    return 0;
}



