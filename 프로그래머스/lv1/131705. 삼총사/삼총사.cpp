#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    sort(number.begin(), number.end());
    
    for (int i = 0; i < number.size()-2; i++) {
        for (int j = i+1; j < number.size()-1; j++) {
            for (int k = j+1; k < number.size(); k++) {
                int sum = number[i]+number[j]+number[k];
                if (sum == 0) {
                    answer++;
                }
                else if (sum > 0) {
                    break;
                }
            }
        }
    }
    
    
    
    return answer;
}