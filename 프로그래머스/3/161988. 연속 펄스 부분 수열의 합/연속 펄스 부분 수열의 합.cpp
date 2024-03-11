#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long sequence1[500000];
long long sequence2[500000];
long long dp1[500000];
long long dp2[500000];

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    for (int i = 0; i < sequence.size(); i++) {
        if (i % 2 == 0) {
            sequence1[i] = sequence[i];
            sequence2[i] = sequence[i] * (-1);
        }
        else {
            sequence1[i] = sequence[i] * (-1);
            sequence2[i] = sequence[i];
        }
    }
    
    dp1[0] = sequence1[0];
    dp2[0] = sequence2[0];
    answer = max(dp1[0], dp2[0]);
    for (int i = 1; i < sequence.size(); i++) {
        dp1[i] = max(dp1[i-1]+sequence1[i], sequence1[i]);
        dp2[i] = max(dp2[i-1]+sequence2[i], sequence2[i]);
        
        answer = max(answer, max(dp1[i], dp2[i]));
    }
    
    return answer;
}