#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for (int i = 0; i <= d; i+=k) {
        answer += (long long)sqrt((long long)d*d - (long long)i*i)/(long long)k + 1;
        //cout << answer << endl;
    }
    
    return answer;
}