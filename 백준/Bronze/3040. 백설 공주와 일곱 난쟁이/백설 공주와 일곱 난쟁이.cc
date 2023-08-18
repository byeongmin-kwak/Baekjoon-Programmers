#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[9];
bool visited[9];
vector<int> v;

void solve(int depth, int sum) {
    if (depth == 7) {
        if (sum == 100) {
            sort(v.begin(), v.end());
            for (int i = 0; i < 7; i++) {
                cout << v[i] << endl;
            }
            exit(0);
        }
        return;
    }
    
    for (int i = 0; i < 9; i++) {
        if (!visited[i]) {
            sum += arr[i];
            v.push_back(arr[i]);
            visited[i] = true;
            solve(depth+1, sum);
            visited[i] = false;
            sum -= arr[i];
            v.pop_back();
        }
    }
}

int main() {
    
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
    }
    
    solve(0, 0);
    
}
