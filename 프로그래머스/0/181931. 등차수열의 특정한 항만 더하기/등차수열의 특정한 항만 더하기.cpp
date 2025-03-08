#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    
    int sum = a;
    if (included[0]) answer += sum;
    
    for (int i = 1; i < included.size(); i++) {
        sum += d;
        if (included[i]) {
            answer += sum;
        }
    }
    return answer;
}