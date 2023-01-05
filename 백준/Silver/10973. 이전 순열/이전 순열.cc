#include <bits/stdc++.h>

using namespace std;

bool prev_permutation(int arr[], int N) {
    
    int i = N-1;
    
    while (i > 0 && arr[i] > arr[i-1]) {
        i--;
    }
    if (i == 0) {
        return false;
    }
    
    int j = N-1;
    while (arr[i-1] < arr[j]) {
        j--;
    }
    swap(arr[i-1], arr[j]);
    
    for (int j = N-1; j > i; j--) {
        swap(arr[i], arr[j]);
        i++;
    }
    return true;
}


int main() {
    
    int arr[10000], N;
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    if (prev_permutation(arr, N)) {
        for (int i = 0; i < N; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }
    
    
}
