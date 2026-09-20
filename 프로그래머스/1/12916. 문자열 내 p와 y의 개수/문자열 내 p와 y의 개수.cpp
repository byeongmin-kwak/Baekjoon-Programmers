#include <string>
#include <iostream>
#include <cctype>

using namespace std;

bool solution(string s) {
    bool answer = true;

    int cnt = 0;
    
    for (char c: s) {
        char lower_c = tolower(c);
        
        if (lower_c == 'p') {
            cnt += 1;
        } else if (lower_c == 'y') {
            cnt -= 1;
        }
    }
    
    if (cnt != 0) {
        answer = false;
    }
    
    return answer;
}