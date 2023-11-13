#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool visited[50];
int answer = 100;

void solve(string begin, string target, vector<string> &words, int cnt) {
    if (begin == target) {
        answer = min(answer, cnt);
    }
    
    if (cnt == words.size()) return;
    
    for (int i = 0; i < words.size(); i++) {
        if (!visited[i]) {
            int tmp = 0;
            bool check = true;
            for (int index = 0; index < begin.size(); index++) {
                if (begin[index] != words[i][index]) tmp++;
                if (tmp >= 2) {
                    check = false;
                    break;
                }
            }
            if (check) {
                visited[i] = true;
                solve(words[i], target, words, cnt+1);
                visited[i] = false;
            }
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }
    
    solve(begin, target, words, 0);
    
    
    return answer;
}