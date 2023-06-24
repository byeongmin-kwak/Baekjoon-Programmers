#include <string>
#include <vector>
#include <iostream>

using namespace std;

int alphabet[26];

vector<int> solution(string s) {
    vector<int> answer;
    
    for (int i = 0; i < 26; i++) {
        alphabet[i] = -1;
    }

    answer.push_back(-1);
    alphabet[(int)s[0]-97] = 0;
    
    
    for (int i = 1; i < s.size(); i++) {
        if (alphabet[(int)s[i]-97] == -1) {
            alphabet[(int)s[i]-97] = i;
            answer.push_back(-1);
        }
        else {
            answer.push_back(i-alphabet[(int)s[i]-97]);
            alphabet[(int)s[i]-97] = i;
        }
    }
    
    return answer;
}