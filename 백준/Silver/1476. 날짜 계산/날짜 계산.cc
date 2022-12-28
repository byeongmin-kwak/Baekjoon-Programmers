#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int E, S, M;
    cin >> E >> S >> M;
    
    int result = 1;
      
    while (true) {
        if ((result-E) % 15 == 0 and (result-S) % 28 == 0 and (result-M) % 19 == 0) {
            cout << result << endl;
            break;
        }
        result++;

    }
    
}
