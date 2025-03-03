#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool check(vector<vector<string>>& park, int size, int y, int x) {
    if (y+size > park.size() || x+size > park[0].size()) {
        return false;
    }
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {      
            if (park[y+i][x+j] != "-1") {
                return false;
            }
        }
    }
    return true;
}

int func(vector<vector<string>>& park, int size) {
    int result = -1;
    
    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[i].size(); j++) {
            if (check(park, size, i, j)) {
                return size;
            }
        }
    }
    
    return result;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    
    for (int i = 0; i < mats.size(); i++) {
        answer = max(answer, func(park, mats[i]));    
    }
    
    return answer;
}