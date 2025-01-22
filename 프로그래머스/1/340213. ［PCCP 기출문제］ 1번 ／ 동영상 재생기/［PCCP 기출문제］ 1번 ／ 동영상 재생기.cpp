#include <string>
#include <vector>
#include <iomanip>
using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    answer = pos;
    for (int i = 0; i < commands.size(); i++) {
        if (answer >= op_start && answer <= op_end) {
            answer = op_end;
        }
        int totalTime;
        if (commands[i] == "next") {
            totalTime = stoi(answer.substr(0,2)) * 60 + stoi(answer.substr(3,5)) + 10;
        }
        else {
            totalTime = stoi(answer.substr(0,2)) * 60 + stoi(answer.substr(3,5)) - 10;
        }
        int hour = totalTime / 60;
        int minute = totalTime % 60;
        ostringstream oss;
        oss << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute;
        answer = oss.str();
        
        if (answer < "00:00") answer = "00:00";
        if (answer > video_len) answer = video_len;
    }
    
    if (answer >= op_start && answer <= op_end) {
        answer = op_end;
    }

    return answer;
}