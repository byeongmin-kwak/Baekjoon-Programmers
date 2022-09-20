#include <bits/stdc++.h>

using namespace std;

int arr[2188][2188];

int result[3];

void paper(int x, int y, int size) {
    int check = arr[x][y];
    bool check_break = true;
    
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (check == -1 and (arr[i][j] == 0 or arr[i][j] == 1)) {
                check_break = false;
                break;
            }
            else if (check == 0 and (arr[i][j] == -1 or arr[i][j] == 1)) {
                check_break = false;
                break;
            }
            else if (check == 1 and (arr[i][j] == -1 or arr[i][j] == 0)) {
                check_break = false;
                break;
            }
        }
        if (check_break == false) {
            break;
        }
    }
    if (check_break == false) {
        paper(x, y, size / 3);
        paper(x, y + size / 3, size / 3);
        paper(x, y + (size / 3) * 2, size / 3);
        paper(x + size / 3, y, size / 3);
        paper(x + size /3 , y + size / 3, size / 3);
        paper(x + size / 3, y + (size / 3) * 2, size / 3);
        paper(x + (size / 3) * 2, y, size / 3);
        paper(x + (size / 3) * 2, y + size / 3, size / 3);
        paper(x + (size / 3) * 2, y + (size / 3) * 2, size / 3);
    }
    else {
        result[arr[x][y]+1]++;
    }
}

int main() {
    
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    
    paper(1, 1, N);
    
    cout << result[0] << '\n' << result[1] << '\n' << result[2];
}
