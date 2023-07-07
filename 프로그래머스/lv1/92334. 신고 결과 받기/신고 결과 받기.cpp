#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include<sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(),report.end()),report.end());
    map<string, pair<vector<string>, int>> m;
    
    
    for (int i = 0; i < report.size(); i++) {
        istringstream ss(report[i]);
        string stringBuffer;
        vector<string> v;
        v.clear();
        while (getline(ss, stringBuffer, ' ')) {
            v.push_back(stringBuffer);
        }
        m[v[0]].first.push_back(v[1]);
        m[v[1]].second++;
    }
    
    for (int i = 0; i < id_list.size(); i++) {
        int tmp = 0;
        for (int j = 0; j < m[id_list[i]].first.size(); j++) {
            if (m[m[id_list[i]].first[j]].second >= k) {
                tmp++;
            }
        }
        answer.push_back(tmp);
     }
    
    
    return answer;
}