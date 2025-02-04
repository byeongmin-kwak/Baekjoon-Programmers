#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool puzzle(vector<int> diffs, vector<int> times, long long limit, int level) {
    
    long long sum = 0;
    int prevTime = 0;
    
    for (int i = 0; i < diffs.size(); i++) {
        if (diffs[i] <= level) {
            sum += times[i];
        }
        else {
            sum += (prevTime+times[i])*(diffs[i]-level) + times[i];
        }
        prevTime = times[i];
    }
    
    return limit >= sum;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    int maxIdx = max_element(diffs.begin(), diffs.end()) - diffs.begin();
    int maxValue = *max_element(diffs.begin(), diffs.end());
    
    int left = 1, right = maxValue;
    
    while(left <= right) {
        int mid = (left+right)/2;
        
        if (puzzle(diffs, times, limit, mid)) {
            right = mid - 1;
            answer = mid;
        }
        else {
            left = mid + 1;
        }
    }
    
    return answer;
}

