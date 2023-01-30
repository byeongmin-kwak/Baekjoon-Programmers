#include <bits/stdc++.h>

using namespace std;
 
int N, S, arr[20], cnt = 0;
vector<int> v;
bool check[20];

void solve(int depth, int size, int index) {
    if (depth == size) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += v[i];
        }
        if (sum == S)
            cnt++;
        
        return;
    }
    for (int i = index; i < N; i++) {
        if (check[i] == true)
            continue;
        v.push_back(arr[i]);
        check[i] = true;
        solve(depth+1, size, i);
        v.pop_back();
        check[i] = false;
    }
    
    
    
}

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    
    cin >> N >> S;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    for (int i = 1; i <= N; i++) {
        solve(0, i, 0);
    }
    
    
    cout << cnt << endl;
}
