#include <bits/stdc++.h>

using namespace std;

vector<int> crane, box;
int N, M;
int ans;
int arr[10000];

int main() {
    
    cin >> N;
    
    int value;
    for (int i = 0; i < N; i++) {
        cin >> value;
        crane.push_back(value);
    }
    
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        cin >> value;
        box.push_back(value);
    }
    
    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end());
    
    if (crane[crane.size() - 1] < box[box.size() - 1]) {
        cout << -1 << '\n';
        return 0;
    }
    
    int cnt = 0;
    while (!box.empty()) {
            cnt++;
            // 크레인 가장 큰 무게 부터
            for (int i = crane.size() - 1; i >= 0; i--) {
                // 상자 가장 큰 무게 부터
                for (int j = box.size() - 1; j >= 0; j--) {
                    // 옮길 수 있으면 삭제하고 다음 크레인으로
                    if (crane[i] >= box[j]) {
                        box.erase(box.begin() + j);
                        break;
                    }
                }
            }
        }
        cout << cnt << '\n';
        return 0;
}

