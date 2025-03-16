#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    int sum = 0;
    int mult = 1;
    for (int i = 0; i < num_list.size(); i++) {
        sum += num_list[i];
        mult *= num_list[i];
    }
    
    if (mult < sum * sum) answer = 1;
    return answer;
}