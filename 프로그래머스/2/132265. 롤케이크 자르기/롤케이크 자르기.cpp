#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    map<int, int> a;
    map<int, int> b;
    
    for (int elem : topping) {
        a[elem]++;       
    }
    
    for (int i = 1; i <= 4; i++) {
        cout << a[i] << ' ';
    }
    
    
    
    return answer;
}