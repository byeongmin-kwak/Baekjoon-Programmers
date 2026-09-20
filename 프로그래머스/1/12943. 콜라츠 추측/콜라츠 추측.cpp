#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    
    if (num == 1) {
        return 0;
    }
    
    while (answer < 500) {
        answer++;
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n*3 + 1;
        }
        
        if (n == 1) {
            return answer;
        }
    }
    
    return -1;
}