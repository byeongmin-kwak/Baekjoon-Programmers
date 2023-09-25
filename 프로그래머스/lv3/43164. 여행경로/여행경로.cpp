#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> v[10001];
vector<string> answer;
map<string, int> m;
bool visited[10001][10001];
int target = 0;
bool flag = false;

void solve(string current) {
    if (flag) {
        return;
    }
    if (answer.size() == target) {
        flag = true;
        return;
    }
    sort(v[m[current]].begin(), v[m[current]].end());
    
    for (int i = 0; i < v[m[current]].size(); i++) {
        if (visited[m[current]][i]) {
            continue;
        }
        else {
            visited[m[current]][i] = true;
            string next = v[m[current]][i];
            answer.push_back(next);
            solve(next);
            if (flag) {
                return;
            }
            else {
                answer.pop_back();
                visited[m[current]][i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    int idx = 1;
    for (auto elem : tickets) {
        if (m[elem[0]] == 0) {
            m[elem[0]] = idx;
            idx++;
        }
        v[m[elem[0]]].push_back(elem[1]);
    }
    target = tickets.size()+1;
    answer.push_back("ICN");
    solve("ICN");
    
    return answer;
}