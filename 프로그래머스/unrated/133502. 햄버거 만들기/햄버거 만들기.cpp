#include <string>
#include <vector>

using namespace std;

int solution(vector<int> v) {
    string s;
    int cnt = 0;
    int len = 0;
    
    for (int i = 0; i < v.size(); i++) {
        s += to_string(v[i]);
        
        if (s.size() >= 4) {
            if (s.substr(s.size()-4, 4) == "1231") {
                cnt++;
                s.erase(s.size()-4, 4);
            }
        }
    }
    int answer = cnt;
    return answer;
}