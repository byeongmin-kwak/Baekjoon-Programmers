#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[10];

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    for (int i = 0; i < score.size(); i++) {
        arr[score[i]]++;
    }
    
    int tmp = 0;
    
    for (int i = k; i > 0; i--) {
        if (arr[i] > 0) {
            arr[i] += tmp;
            tmp = 0;
            answer += (arr[i] / m) * i * m;
            tmp += arr[i] % m;
        }
    }
    
    
    return answer;
}