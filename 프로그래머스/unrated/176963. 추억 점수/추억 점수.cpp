#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string,int> m;
    
    for (int i = 0; i < name.size(); i++) {
        m.insert({name[i],yearning[i]});
    }
    
    int tmp;
    for (int i = 0; i < photo.size(); i++) {
        tmp = 0;
        for (int j = 0; j < photo[i].size(); j++) {
            tmp += m[photo[i][j]];
        }
        answer.push_back(tmp);
    }
    
    return answer;
}