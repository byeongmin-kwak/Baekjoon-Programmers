#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool checkCorrect(string s) {
    stack<char> st;
    bool ans = true;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push('(');
        }
        else {
            if (st.empty()) {
                ans = false;
                break;
            }
            else {
                st.pop();
            }
        }
    }
    
    return ans;
}



string u_v(string p) {
    if (p.size() == 0) {
        return "";
    }
    
    int open = 0;
    int close = 0;
    string u = "";
    string v = "";
    int idx = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            u += '(';
            open++;
        }
        else {
            u += ')';
            close++;
        }
        
        if (open == close) {
            idx = i+1;
            break;
        }
    }
    
    v = p.substr(idx);
    
    if (checkCorrect(u)) {
        return u + u_v(v);
    }
    else {
        string s = "";
        s += '(';
        s += u_v(v);
        s += ')';
        for (int i = 1; i < u.size()-1; i++) {
            if (u[i] == '(') {
               s += ')'; 
            }
            else {
                s += '(';
            }
        }
        return s;
    }
}

string solution(string p) {
    string answer = "";
    
    if (p.size() == 0) {
        return answer;
    }
    
    string u = "";
    string v = "";
    
    answer = u_v(p);
    
    
    
    
    
    
    return answer;
}