#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int colIdx;

bool compare(vector<int> v1, vector<int> v2) {
    if (v1[colIdx] == v2[colIdx]) {
        return v1[0] > v2[0];
    }
    else {
        return v1[colIdx] < v2[colIdx];
    }
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    colIdx = col - 1;
    
    sort(data.begin(), data.end(), compare);
    
    for (int i = row_begin-1; i < row_end; i++) {
        int S = 0;
        for (int j = 0; j < data[i].size(); j++) {
            S += data[i][j] % (i+1);
        }
        answer ^= S;
    }
    
    
    return answer;
}