#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> st;
    int current = 1;
    bool check;
    for (int i = 0; i < order.size(); i++) {
        check = false;
        while (order[i] > current) {
            st.push(current);
            current++;
        }
        if (current == order[i]) {
            current++;
            answer++;
            continue;
        }
        if (st.top() == order[i]) {
            st.pop();
            answer++;
            continue;
        }
        break;
    }
    
    return answer;
}