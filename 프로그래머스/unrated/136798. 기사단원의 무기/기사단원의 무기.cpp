#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int i = 1; i <= number; i++) {
        int tmp = 0;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                tmp += 2;
                if (j * j == i) {
                    tmp--;
                }
            }
        }
        if (tmp <= limit) {
            answer += tmp;
        }
        else {
            answer += power;
        }
        
    }
    
    return answer;
}