#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<int, string> m1;
    map<string, int> m2;
    
    for (int i = 0; i < players.size(); i++) {
        m1[i] = players[i];
        m2[players[i]] = i;
    }
    
    for (int i = 0; i < callings.size(); i++) {
        int index = m2[callings[i]];
        string change = m1[index-1];
        m1[index-1] = callings[i];
        m1[index] = change;
        m2[callings[i]] -= 1;
        m2[change] += 1;
    }
    
    for (auto elem : m1) {
        answer.push_back(elem.second);
    }
    
    return answer;
}
