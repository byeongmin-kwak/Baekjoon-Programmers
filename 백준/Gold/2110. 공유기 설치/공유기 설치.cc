#include <bits/stdc++.h>

using namespace std;
 
int main() {

    vector<int> v;
    int N, C;
    cin >> N >> C;
 
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }
 

    sort(v.begin(), v.end());
 
    // 이진 탐색을 이용하여 존재할 수 있는 간격의 값을 찾는다.
    // 간격의 값은 최대 좌표의 시작점과 끝점의 값의 차이이다. 
    int left = 1;
    int right = v.back();
    int ans = -1;
 
    while (left <= right) {
        int mid = (left + right) / 2;
        int before_set_index = 0;
        int set_num = 1;
 
        // 하나하나 건너 뛰면서 공유기의 값이 현재 값의 mid 이상인 경우에만 설치 가능하다
        for (int i = 1; i < N; i++) {
 
            // 현재 위치와 직전 설치한 공유기의 위치의 간격이 mid 보다 크다면
            if (v.at(i) - v.at(before_set_index) >= mid) {
                before_set_index = i;
                set_num++; 
            } 
        }
        
        // 모든 인덱스를 확인하면 갯수가 입력받은 C보다 큰지 확인한다. 
        // C 보다 크면 현재의 최대값이 되고, left를 변경하여 더 큰 값을 탐색하고 반대인 경우 right 를 변경
        if (set_num >= C) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
 
        // 현재의 설치 대수보다 더 크면 정답을 교체한다. 
        if (ans < mid && set_num >= C)
            ans = mid;
 
    }
 
    cout << ans;
 
    return 0; 
}
