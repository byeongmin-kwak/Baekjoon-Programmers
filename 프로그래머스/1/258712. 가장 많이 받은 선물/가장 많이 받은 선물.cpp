#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    int log[50][50] = {0, }, giftSum[50] = {0, }, nextReceive[50] = {0, };
    
    for (string s : gifts) {
        int blankIdx = s.find(' ');
        
        string giver = s.substr(0, blankIdx);
        string receiver = s.substr(blankIdx+1);
        
        int giverIdx = find(friends.begin(), friends.end(), giver) - friends.begin();
        int receiverIdx = find(friends.begin(), friends.end(), receiver) - friends.begin();
        
        log[giverIdx][receiverIdx]++;
        
        giftSum[giverIdx]++;
        giftSum[receiverIdx]--;
    }
    
    for (int i = 0; i < friends.size(); i++) {
        for (int j = 0; j < friends.size(); j++) {
            if (i == j) continue;
            
            if (log[i][j] || log[j][i]) {
                if (log[i][j] > log[j][i]) {
                    nextReceive[i]++;
                }
                else if (log[i][j] == log[j][i] && giftSum[i] > giftSum[j]) {
                    nextReceive[i]++;
                }
            }
            else {
                if (giftSum[i] > giftSum[j]) {
                    nextReceive[i]++;
                }
            }
        }
        answer = max(answer, nextReceive[i]);
    }
    
    return answer;
}