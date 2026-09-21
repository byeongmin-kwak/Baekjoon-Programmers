#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toBinary(int n) {
    string binary = "";
    if (n == 0) {return "0";}
    while (n > 0) {
        binary += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

vector<int> solution(string s) {
    vector<int> answer = {0, 0};
    
    while(s != "1") {
        int current_zero = 0;
        int current_length = 0;
        
        for (char c : s) {
            if (c == '1') {
                current_length++;
            } else {
                current_zero++;
            }
        }
        answer[1] += current_zero;
        answer[0]++;
        s = toBinary(current_length);
    }
    
    return answer;
}