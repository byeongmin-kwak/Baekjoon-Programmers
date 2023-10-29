#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> m;
    
    for (int i = 0; i < tangerine.size(); i++) {
        m[tangerine[i]]++;
    }
    
    vector<int> v;
    
    for (auto iter : m) {
        v.push_back(iter.second);
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    for (int i = 0; i < v.size(); i++) {
        k -= v[i];
        answer++;
        if (k <= 0) {
            break;
        }
    }
    
    return answer;
}