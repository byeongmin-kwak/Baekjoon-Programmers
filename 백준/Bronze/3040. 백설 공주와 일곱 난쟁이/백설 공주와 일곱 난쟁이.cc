#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
    int sum = 0;
    int num;
    for (int i = 0; i < 9; i++) {
        cin >> num;
        v.push_back(num);
        sum += num;
    }
    
    sort(v.begin(),v.end());
    
    for (int i = 0; i < 8; i++) {
        for (int j = i+1; j < 9; j++) {
            if (sum - (v[i]+v[j]) == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j) {
                        cout << v[k] << ' ';
                    }
                }
                return 0;
            }
        }
    }
}
