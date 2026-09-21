#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    
    int num;
    ss >> num;
    int min_val = num;
    int max_val = num;
    
    while (ss >> num) {
        min_val = min(min_val, num);
        max_val = max(max_val, num);
    }
    
    answer += to_string(min_val) + " " + to_string(max_val);
    
    return answer;
}