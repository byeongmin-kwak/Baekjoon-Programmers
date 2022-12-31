#include <bits/stdc++.h>

using namespace std;

int main(){

    int N, M;
    cin >> N >> M;
    char broken[10];
    for (int i = 0; i < M; i++) {
        cin >> broken[i];
    }
    
    int first = 9999999;
    int second = 9999999;
    
    string NString;
    bool check;
    for (int i = N; i >= 0; i--) {
        NString = to_string(i);
        check = true;
        for (int j = 0; j < M; j++) {
            if (NString.find(broken[j]) != string::npos) {
                check = false;
                break;
            }
        }
        if (check == true) {
            first = i;
            break;
        }
    }
    
    for (int i = N; i <= N + abs(N-100); i++) {
        check = true;
        NString = to_string(i);
        for (int j = 0; j < M; j++) {
            if (NString.find(broken[j]) != string::npos) {
                check = false;
                break;
            }
        }
        if (check == true) {
            second = i;
            break;
        }
    }
    first = to_string(first).length() + abs(N - first);
    second = to_string(second).length() + abs(N - second);
    int third = abs(N-100);
    
    int result = min(first, min(second, third));
        
    cout << result << endl;
    
    
    
    
    
    
}

