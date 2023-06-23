#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long num = stoll(p);
    
    for (int i = 0; i < t.size()-p.size()+1; i++) {
        if (stoll(t.substr(i,p.size())) <= num) {
            answer++;
        }
    }
    return answer;
}