#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    long long min_val = min(a, b);
    long long max_val = max(a, b);
    
    answer = (min_val + max_val) * (max_val - min_val + 1) / 2;
    
    return answer;
}