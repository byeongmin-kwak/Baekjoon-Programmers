#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    int tmp;
    while(storey != 0) {
        tmp = storey % 10;
        
        if (tmp < 5) {
            answer += tmp;
            storey /= 10;
        }
        else if (tmp > 5) {
            answer += 10-tmp;
            storey /= 10;
            storey++;
        }
        else {
            answer += 5;
            if ((storey % 100) / 10 >= 5) {
                storey /= 10;
                storey++;
            }
            else {
                storey /= 10;
            }
        }   
    }

    return answer;
}