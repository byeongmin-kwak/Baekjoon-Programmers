#include <bits/stdc++.h>

using namespace std;


int main() {


    string s;
    cin >> s;
    
    string arr[1000];

    for (int i = 0 ; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            arr[i] += s[j];
        }
    }
    
    priority_queue<string, vector<string>, greater<string>> pq;
    
    for (int i = 0;i < s.length(); i++) {
        pq.push(arr[i]);
    }
    
    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    
    
    return 0;
}



