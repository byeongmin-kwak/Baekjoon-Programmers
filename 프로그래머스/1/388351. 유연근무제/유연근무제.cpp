#include <string>
#include <vector>

using namespace std;

bool check(int start, vector<int>& timelogs, int startday) {
    start += 10;
    if ((start / 10) % 10 == 6) {
        start += 40;
    }
    
    for (int i = 0; i < timelogs.size(); i++) {
        if (startday == 6 || startday == 7 || startday == 13) {
            startday++;
            continue;
        }
        if (start < timelogs[i]) {
            return false;
        }
        startday++;
    }
    
    
    return true;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for (int i = 0; i < schedules.size(); i++) {
        if (check(schedules[i], timelogs[i], startday)) {
            answer++;
        }
    }
    
    return answer;
}