#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<int> v;
    
    while(k != 1) {
        v.push_back(k);        
        
        if (k % 2 == 0) {
            k /= 2;
        }
        else {
            k = k * 3 + 1;
        }
    }
    v.push_back(1);
    
    for (int i = 0; i < ranges.size(); i++) {
        int start = ranges[i][0];
        int end = (v.size() -1) + ranges[i][1];
        
        double result = 0;
        for (int j = start; j < end; j++) {
            result += (double)(v[j] + v[j+1]) / 2;
        }
        if (start > end) {
            result = -1.0;
        }
        answer.push_back(result);
    }
    
    return answer;
}