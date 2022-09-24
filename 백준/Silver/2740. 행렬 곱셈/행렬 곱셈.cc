#include <bits/stdc++.h>
#define num 1000000007

using namespace std;

int arrA[101][101];
int arrB[101][101];
int arrC[101][101];


int main() {
        
    int NA, KA;
    cin >> NA >> KA;
    
    for (int i = 1; i <= NA; i++) {
        for (int j = 1; j <= KA; j++) {
            cin >> arrA[i][j];
        }
    }
    
    int NB, KB;
    cin >> NB >> KB;
    
    for (int i = 1; i <= NB; i++) {
        for (int j = 1; j <= KB; j++) {
            cin >> arrB[i][j];
        }
    }
    
    for (int i = 1; i <= NA; i++) {
        for (int j = 1; j <= KB; j++) {
            for (int k = 1; k <= KA; k++) {
                arrC[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    
    for (int i = 1; i <= NA; i++) {
        for (int j = 1; j <= KB; j++) {
            cout << arrC[i][j] << ' ';
        }
        cout << '\n';
    }
    
    
}
