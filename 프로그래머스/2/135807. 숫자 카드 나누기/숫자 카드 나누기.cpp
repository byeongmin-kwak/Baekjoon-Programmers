#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long x, long long y){
    if (y == 0){
        return x;
    } 
    else {
        return gcd(y, x%y);
    }
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int gcdA = arrayA[0];
    int gcdB = arrayB[0];

    
    for (int i = 1; i < arrayA.size(); i++) {
        gcdA = gcd(gcdA, arrayA[i]);
        gcdB = gcd(gcdB, arrayB[i]);
    }
    
    bool check = false;
    for (int i = 0; i < arrayB.size(); i++) {
        if (arrayB[i] % gcdA == 0) {
            check = true;
            break;
        }
    }
    
    if (!check) {
        answer = gcdA;
    }
    
    check = false;
    for (int i = 0; i < arrayA.size(); i++) {
        if (arrayA[i] % gcdB == 0) {
            check = true;
            break;
        }
    }
    
    if (!check) {
        answer = max(answer, gcdB);
    }
    
    return answer;
}