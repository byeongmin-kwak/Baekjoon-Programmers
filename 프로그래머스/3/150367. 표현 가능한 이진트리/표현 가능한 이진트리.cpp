#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v = {1, 3, 7, 15, 31, 63};

bool solve(string ns, char root) {
    if (root == '0' && ns[ns.length()/2] == '1') {
        return false;
    }
    if (ns.length() == 1) {
        return true;
    }
    return solve(ns.substr(0,ns.length()/2),ns[ns.length()/2]) && solve(ns.substr(ns.length()/2+1),ns[ns.length()/2]);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (long long number : numbers) {
        bitset<50> bit(number);
        string s = bit.to_string();
        
        int length = 0;
        for (int i = 0; i < 50; i++) {
            if(s[i] == '1') {
                length = 50 - i;
                break;
            }
        }
        
        string ns = "";
        if (find(v.begin(), v.end(), length) == v.end()) { 
            int target;
	        for (int i = 0; i < 6; i++) {
                if (length < v[i]) {
                    target = v[i];
                    break;
                }
            }
            for (int i = 0; i < target-length; i++) {
                ns += '0';
            }
        }
        for (int i = 50-length; i < 50; i++) {
            ns += s[i];
        }
        answer.push_back(solve(ns,ns[ns.length()/2]));
    }
    
    return answer;
}