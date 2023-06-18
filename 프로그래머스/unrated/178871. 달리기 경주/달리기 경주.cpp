#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<int,string> m1;
map<string, int> m2;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    for (int i = 0; i < players.size(); i++) {
        m1[i+1] = players[i];
        m2[players[i]] = i+1;
    }
    
    for (int i = 0; i < callings.size(); i++) {
        int idx = m2[callings[i]];
        string name = m1[idx-1];
        
        m1[idx-1] = callings[i];
        m1[idx] = name;
        m2[callings[i]] = idx - 1;
        m2[name] = idx;
        
    }
    
    for (int i = 1; i <= players.size(); i++) {
        answer.push_back(m1[i]);
    }
    
    return answer;
}