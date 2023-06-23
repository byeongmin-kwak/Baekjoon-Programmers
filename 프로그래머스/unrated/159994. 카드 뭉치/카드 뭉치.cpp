#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int a = 0;
    int b = 0;
    bool check = true;
    
    for (int i = 0; i < goal.size(); i++) {
        if (cards1[a] == goal[i]) {
            a++;
            continue;
        }
        else if (cards2[b] == goal[i]) {
            b++;
            continue;
        }
        else {
            check = false;
            break;
        }
    }
    if (check) {
        answer += "Yes";
    }
    else {
        answer += "No";
    }
    
    return answer;
}