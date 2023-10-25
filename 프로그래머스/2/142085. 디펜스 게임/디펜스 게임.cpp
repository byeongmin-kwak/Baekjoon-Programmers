#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    
    for (int i = 0; i < enemy.size(); i++) {
        pq.push(enemy[i]*(-1));
        if (pq.size() > k) {
            n += pq.top();
            pq.pop();
        }
        if (n < 0) {
            answer = i;
            break;
        }
    }
    if (answer == 0) {
        answer = enemy.size();
    }
    
    return answer;
}