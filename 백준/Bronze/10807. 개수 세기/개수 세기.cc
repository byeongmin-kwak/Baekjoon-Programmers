#include <iostream>

using namespace std;

int arr[100];

int main() {
    
    int N, v;
    int answer = 0;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> v;
    
    
    for (int i = 0; i < N; i++) {
        if (arr[i] == v) {
            answer++;
        }
    }
    
    cout << answer << endl;
    
}
