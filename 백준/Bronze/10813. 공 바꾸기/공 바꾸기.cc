#include <iostream>

using namespace std;

int arr[101];

int main() {
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        arr[i] = i;
    }
    
    int a, b;
    while(M--) {
        cin >> a >> b;
        
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
    
    for (int i = 1; i <= N; i++) {
        cout << arr[i] << ' ';
    }
    
    
    
    
}
