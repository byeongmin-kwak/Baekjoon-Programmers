#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    queue<int> que;
    for (int i = 0; i < players.size(); i++) {

        
        // 사라지는 서버
        while (que.size() > 0) {
            if (que.front()+k == i) {
                que.pop();
            } else {
                break;
            }   
        }
        
        // 증설을 해야하는 상황
        if (players[i] >= (que.size()+1)*m) {
            int plus = (players[i]/m) - que.size();
            answer += plus;
            while (plus--) {
                que.push(i);
            }
        }
        // cout << que.size() << endl;
    }
    
    return answer;
}