#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;
    
    int sum = 0;
    int newOpen = 0;
    int open = 0;
    bool preCheck = false;
    
    for (int i = 0 ; i < s.size(); i++) {
        
        if (s[i] == '(') {
            newOpen += 1;
            preCheck = true;
        }
        else if (s[i] == ')') {
            if (preCheck == true) {
                newOpen -= 1;

                sum += newOpen * 2 + open;
                
                open += newOpen;
                newOpen = 0;
                preCheck = false;

            }
            else {
                open -= 1;
            }
        }
    }
    
    
    cout << sum << endl;
    
    return 0;
}
