#include <bits/stdc++.h>

using namespace std;

int arr1[1000001];
int arr2[1000001];
int arr3[1000001];

int main() {
    
    
    int N;
    cin >> N;
        
    int num;
    int max = 0;
    for (int i = 0; i < N; i++) {
        cin >> num;
        arr1[i] = num;
        arr2[num]++;
        
        if (arr2[num] > arr2[max]) {
            max = num;
        }
    }
    
    for (int i = 0; i < N; i++) {
        bool find = false;
        for (int j = i + 1; j < N; j++) {
            if (arr1[i] == max) {
                arr3[i] = -1;
                break;
            }
            if (arr2[arr1[i]] < arr2[arr1[j]]) {
                arr3[i] = arr1[j];
                find = true;
                break;
            }
        }
        if (find == false) {
            arr3[i] = -1;
        }
    }


    for (int i = 0; i < N; i++) {
        cout << arr3[i] << ' ';
    }
    
    cout << endl;
    
    
    return 0;
}
