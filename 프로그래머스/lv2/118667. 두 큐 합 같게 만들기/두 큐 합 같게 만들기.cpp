#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    
    queue<int> que1;
    queue<int> que2;
    
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < queue1.size(); i++) {
        sum1 += queue1[i];
        que1.push(queue1[i]);
        sum2 += queue2[i];
        que2.push(queue2[i]);
    }
    long long target = (sum1 + sum2) / 2;
        
    int cnt = 0;
    for (int i = 0; i <= 3 * queue1.size(); i++) {
        if (sum1 > sum2) {
            sum1 -= que1.front();
            sum2 += que1.front();
            que2.push(que1.front());
            que1.pop();
            cnt++;
        }
        else if (sum1 < sum2) {
            sum2 -= que2.front();
            sum1 += que2.front();
            que1.push(que2.front());
            que2.pop();
            cnt++;
        }
        else {
            answer = cnt;
            break;
        }
    }
    
    return answer;
}