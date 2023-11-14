#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare1(pair<int, string> p1, pair<int, string> p2) {
    return p1.first > p2.first;
}

bool compare2(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    vector<pair<int, string>> v1(10001);
    vector<vector<pair<int, int>>> v2(10001);
    
    int idx = 1;
    for (int i = 0; i < genres.size(); i++) {
        if (m[genres[i]] == 0) {
            m[genres[i]] = idx;
            v1[m[genres[i]]].second = genres[i];
            idx++;
        }
        v1[m[genres[i]]].first += plays[i];
        v2[m[genres[i]]].push_back({plays[i],i});
    }
    
    sort(v1.begin(), v1.end(), compare1);
    
    for (int i = 1; i <= m.size(); i++) {
        sort(v2[i].begin(), v2[i].end(), compare2);
    }
    
    for (int i = 0; i < m.size(); i++) {
        string genre = v1[i].second;
        int idx = m[genre];
        for (int j = 0; j < v2[idx].size() && j < 2; j++) {
            answer.push_back(v2[idx][j].second);
        }
    }
    
    
    
    return answer;
}