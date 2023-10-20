#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solve(long long n, long long l, long long r) {
    if (l > r) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    n /= 5;
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 2) continue;
        ans += solve(n, max(n*i,l) - (n*i), min(n*(i+1)-1,r) - (n*i));
    }
    return ans;
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    answer = solve(pow(5,n), l-1, r-1);
    
    return answer;
}