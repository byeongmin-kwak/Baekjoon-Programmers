#include <string>
#include <vector>
#include <iostream>

using namespace std;

int discount[4] = {10, 20, 30, 40};
int discountEmoticons[7];
vector<int> answer(2);


void solve(int depth, vector<int> &emoticons, vector<vector<int>> &users) {
    if (depth == emoticons.size()) {
        int cnt = 0;
        int price = 0;
        for (int i = 0; i < users.size(); i++) {
            int sum = 0;
            for (int j = 0; j < emoticons.size(); j++) {
                if (users[i][0] <= discountEmoticons[j]) {
                    sum += emoticons[j] - (int)emoticons[j] * ((float)discountEmoticons[j] / 100);
                    
                }
            }
            if (sum >= users[i][1]) {
                cnt++;
            }
            else {
                price += sum;
            }
        }
        if (answer[0] < cnt) {
            answer[0] = cnt;
            answer[1] = price;
        }
        else if (answer[0] == cnt) {
            if (answer[1] < price) {
                answer[1] = price;
            }
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        discountEmoticons[depth] = discount[i];
        solve(depth+1, emoticons, users);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    solve(0, emoticons, users);
    return answer;
}