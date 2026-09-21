#include <string>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isFirst = true;
        
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            isFirst = true;
        } else {
            if (isFirst) {
                s[i] = toupper(s[i]);
            } else {
                s[i] = tolower(s[i]);
            }
            isFirst = false;
        }  
    }
    answer = s;
    return answer;
}