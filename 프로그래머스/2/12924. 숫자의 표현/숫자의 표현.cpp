#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    int sum = 1;
    int left = 1;
    int right = 1;
    
    while (left <= n / 2) {
        if (sum == n) answer++;
        
        if (sum >= n) {
            sum -= left;
            left++;
        }
        else {
            right++;
            sum += right;
        }
    }
    
    return answer;
}