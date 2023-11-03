#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    map<int, int> a;
    map<int, int> b;
    int cntA = 0, cntB = 0;
    
    for (int elem : topping) {
        a[elem]++;
        if (a[elem] == 1) cntA++;
    }
    
    for (int elem : topping) {
        a[elem]--;
        b[elem]++;
        if (a[elem] == 0) cntA--;
        if (b[elem] == 1) cntB++;
        if (cntA == cntB) answer++;
    }
    
    return answer;
}