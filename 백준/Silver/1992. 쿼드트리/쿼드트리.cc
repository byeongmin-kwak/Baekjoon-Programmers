#include <bits/stdc++.h>

using namespace std;

int arr[65][65];


void Quad_Tree(int x, int y, int size) {
    int check = arr[x][y];
    bool check2 = true;
    
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (check == 0 and arr[i][j] == 1) {
                check2 = false;
                break;
            }
            else if (check == 1 and arr[i][j] == 0) {
                check2 = false;
                break;
            }
        }
        if (check2 == false) {
            break;
        }
    }
    if (check2 == false) {
        cout << "(";
        Quad_Tree(x, y, size / 2);
        Quad_Tree(x, y + size / 2, size / 2);
        Quad_Tree(x + size / 2, y, size / 2);
        Quad_Tree(x + size / 2, y + size / 2, size / 2);
        cout << ")";
    }
    else {
        cout << arr[x][y];
    }
}

int main() {
    
    int N;
    cin >> N;
    string s;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int j = 1; j <= N; j++) {
            arr[i][j] = s[j-1]-'0';
        }
    }
    
    Quad_Tree(1, 1, N);
    
    
}
