#include <bits/stdc++.h>

using namespace std;

char arr[50][50];

int N;
int maxRow = 0;
int maxCol = 0;

void Check() {
    for (int i = 0; i < N ; i++) {
        int temp = 0;
        for (int j = 1; j < N; j++) {
            if (arr[i][j-1] == arr[i][j]) {
                temp++;
            }
            else {
                maxRow = max(maxRow, temp);
                temp = 0;
            }
        }
        maxRow = max(maxRow, temp);
    }
    
    for (int i = 0; i < N ; i++) {
        int temp = 0;
        for (int j = 1; j < N; j++) {
            if (arr[j-1][i] == arr[j][i]) {
                temp++;
            }
            else {
                maxCol = max(maxCol, temp);
                temp = 0;
            }
        }
        maxCol = max(maxCol, temp);
    }
}

int main() {
    
    cin >> N;
    
    
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-1; j++) {
            swap(arr[i][j], arr[i][j+1]);
            Check();
            swap(arr[i][j], arr[i][j+1]);
            Check();
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-1; j++) {
            swap(arr[j][i], arr[j+1][i]);
            Check();
            swap(arr[j][i], arr[j+1][i]);
            Check();
        }
    }
    
    cout << max(maxRow+1, maxCol+1) << endl;

}

