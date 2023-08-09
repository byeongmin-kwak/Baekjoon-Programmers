#include <iostream>

using namespace std;

int arr[101];

int main() {
    
    int N, M;
    cin >> N >> M;
    int i,j,k;
    while (M--) {
        cin >> i >> j >> k;
        
        for (int index = i; index <= j; index++) {
            arr[index] = k;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        cout << arr[i] << ' ';
    }
    
    
    
    
    
}
