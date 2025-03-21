#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v;

bool check(const vector<vector<int>>& q, const vector<int>& ans) {
    for (int i = 0; i < q.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < v.size(); j++) {
            for (int k = 0; k < q[i].size(); k++) {
                if (v[j] == q[i][k]) {
                    cnt++;
                }
            }
        }
        if (cnt != ans[i]) {
            return false;
        }
    }
    
    return true;
}

void dfs(int& answer, int n, const vector<vector<int>>& q, const vector<int>& ans, int depth, int start) {
    if (depth == 5) {
        // for (int i = 0; i < v.size(); i++) {
        //     cout << v[i] << ' ';
        // }
        // cout << endl;
        if (check(q, ans)) {
            answer++;
        }
        return;
    }
    
    for (int i = start; i <= n; i++) {
        v.push_back(i);
        dfs(answer, n , q, ans, depth+1, i+1);
        v.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    dfs(answer, n, q, ans, 0, 1);
    
    return answer;
}