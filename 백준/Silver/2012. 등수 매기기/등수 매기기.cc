#include <bits/stdc++.h>

using namespace std;

int N;
long long result = 0;
vector<int> v;

int main() {
    
    cin >> N;
    
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    int grade = 1;
    for (int i = 0; i < N; i++) {
        result += abs(grade - v[i]);
        
        grade++;
    }
    
    cout << result << endl;
    
}
