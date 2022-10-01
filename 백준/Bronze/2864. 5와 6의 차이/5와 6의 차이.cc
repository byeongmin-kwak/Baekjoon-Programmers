#include <bits/stdc++.h>

using namespace std;


int main() {

    string s1, s2;
    cin >> s1 >> s2;
    
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == '6') {
            s1[i] = '5';
        }
    }
    
    for (int i = 0; i < s2.length(); i++) {
        if (s2[i] == '6') {
            s2[i] = '5';
        }
    }
    
    cout << stoi(s1) + stoi(s2) << ' ';
    
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == '5') {
            s1[i] = '6';
        }
    }
    
    for (int i = 0; i < s2.length(); i++) {
        if (s2[i] == '5') {
            s2[i] = '6';
        }
    }
    
    cout << stoi(s1) + stoi(s2);

    
}

