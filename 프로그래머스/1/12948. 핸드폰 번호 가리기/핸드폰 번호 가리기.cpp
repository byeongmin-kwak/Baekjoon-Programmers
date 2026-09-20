#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    
    answer += string(phone_number.size() - 4, '*');
    answer += phone_number.substr(phone_number.size() - 4);
    
    return answer;
}