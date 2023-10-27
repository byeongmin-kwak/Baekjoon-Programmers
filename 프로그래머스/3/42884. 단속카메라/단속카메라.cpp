#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end());
    
    stack<int> st;
    st.push(routes[0][1]);
    
    for (int i = 1; i < routes.size(); i++) {
        if (routes[i][0] > st.top()) {
            st.push(routes[i][1]);
        }
        else {
            if (routes[i][1] < st.top()) {
                st.pop();
                st.push(routes[i][1]);
            }
        }
    }
    
    answer = st.size();

    return answer;
}