#include <iostream>

using namespace std;

int arr[19][19];

int main() {
    
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> arr[i][j];
        }
    }
    
    bool flag;
    bool check = false;
    
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (arr[i][j] == 1) {
                // 오른쪽 대각선 위
                flag = true;
                for (int k = 1; k <= 4; k++) {
                    if (i-k >= 0 && j+k < 19) {
                        if (arr[i-k][j+k] != 1) {
                            flag = false;
                            break;
                        }
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (i-5 >= 0 && j+5 < 19) {
                        if (arr[i-5][j+5] != 1) {
                            if (i+1 < 19 && j-1 >= 0) {
                                if (arr[i+1][j-1] != 1) {
                                    cout << 1 << endl << i+1 << ' ' << j+1;
                                    return 0;
                                }
                            }
                            else {
                                cout << 1 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                    }
                    else {
                        if (i+1 < 19 && j-1 >= 0) {
                            if (arr[i+1][j-1] != 1) {
                                cout << 1 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                        else {
                            cout << 1 << endl << i+1 << ' ' << j+1;
                            return 0;
                        }
                    }
                }
                // 오른쪽
                flag = true;
                for (int k = 1; k <= 4; k++) {
                    if (j+k < 19) {
                        if (arr[i][j+k] != 1) {
                            flag = false;
                            break;
                        }
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (j+5 <= 19) {
                        if (arr[i][j+5] != 1) {
                            if (j-1 >= 0) {
                                if (arr[i][j-1] != 1) {
                                    cout << 1 << endl << i+1 << ' ' << j+1;
                                    return 0;
                                }
                            }
                            else {
                                cout << 1 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                    }
                    else {
                        if (j-1 >= 0) {
                            if (arr[i][j-1] != 1) {
                                cout << 1 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                        else {
                            cout << 1 << endl << i+1 << ' ' << j+1;
                            return 0;
                        }
                    }
                }
                // 오른쪽 대각선 아래
                flag = true;
                for (int k = 1; k <= 4; k++) {
                    if (i+k < 19 && j+k < 19) {
                        if (arr[i+k][j+k] != 1) {
                            flag = false;
                            break;
                        }
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (i+5 < 19 && j+5 < 19) {
                        if (arr[i+5][j+5] != 1) {
                            if (i-1 >= 0 && j-1 >= 0) {
                                if (arr[i-1][j-1] != 1) {
                                    cout << 1 << endl << i+1 << ' ' << j+1;
                                    return 0;
                                }
                            }
                            else {
                                cout << 1 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                    }
                    else {
                        if (i-1 >= 0 && j-1 >= 0) {
                            if (arr[i-1][j-1] != 1) {
                                cout << 1 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                        else {
                            cout << 1 << endl << i+1 << ' ' << j+1;
                            return 0;
                        }
                    }
                }
                // 아래
                flag = true;
                for (int k = 1; k <= 4; k++) {
                    if (i+k < 19) {
                        if (arr[i+k][j] != 1) {
                            flag = false;
                            break;
                        }
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (i+5 < 19) {
                        if (arr[i+5][j] != 1) {
                            if (i-1 >= 0) {
                                if (arr[i-1][j] != 1) {
                                    cout << 1 << endl << i+1 << ' ' << j+1;
                                    return 0;
                                }
                            }
                            else {
                                cout << 1 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                    }
                    else {
                        if (i-1 >= 0) {
                            if (arr[i-1][j] != 1) {
                                cout << 1 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                        else {
                            cout << 1 << endl << i+1 << ' ' << j+1;
                            return 0;
                        }
                    }
                }
            }
            
            if (arr[i][j] == 2) {
                // 오른쪽 대각선 위
                flag = true;
                for (int k = 1; k <= 4; k++) {
                    if (i-k >= 0 && j+k < 19) {
                        if (arr[i-k][j+k] != 2) {
                            flag = false;
                            break;
                        }
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (i-5 >= 0 && j+5 < 19) {
                        if (arr[i-5][j+5] != 2) {
                            if (i+1 < 19 && j-1 >= 0) {
                                if (arr[i+1][j-1] != 2) {
                                    cout << 2 << endl << i+1 << ' ' << j+1;
                                    return 0;
                                }
                            }
                            else {
                                cout << 2 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                    }
                    else {
                        if (i+1 < 19 && j-1 >= 0) {
                            if (arr[i+1][j-1] != 2) {
                                cout << 2 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                        else {
                            cout << 2 << endl << i+1 << ' ' << j+1;
                            return 0;
                        }
                    }
                }
                // 오른쪽
                flag = true;
                for (int k = 1; k <= 4; k++) {
                    if (j+k < 19) {
                        if (arr[i][j+k] != 2) {
                            flag = false;
                            break;
                        }
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (j+5 <= 19) {
                        if (arr[i][j+5] != 2) {
                            if (j-1 >= 0) {
                                if (arr[i][j-1] != 2) {
                                    cout << 2 << endl << i+1 << ' ' << j+1;
                                    return 0;
                                }
                            }
                            else {
                                cout << 2 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                    }
                    else {
                        if (j-1 >= 0) {
                            if (arr[i][j-1] != 2) {
                                cout << 2 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                        else {
                            cout << 2 << endl << i+1 << ' ' << j+1;
                            return 0;
                        }
                    }
                }
                // 오른쪽 대각선 아래
                flag = true;
                for (int k = 1; k <= 4; k++) {
                    if (i+k < 19 && j+k < 19) {
                        if (arr[i+k][j+k] != 2) {
                            flag = false;
                            break;
                        }
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (i+5 < 19 && j+5 < 19) {
                        if (arr[i+5][j+5] != 2) {
                            if (i-1 >= 0 && j-1 >= 0) {
                                if (arr[i-1][j-1] != 2) {
                                    cout << 2 << endl << i+1 << ' ' << j+1;
                                    return 0;
                                }
                            }
                            else {
                                cout << 2 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                    }
                    else {
                        if (i-1 >= 0 && j-1 >= 0) {
                            if (arr[i-1][j-1] != 2) {
                                cout << 2 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                        else {
                            cout << 2 << endl << i+1 << ' ' << j+1;
                            return 0;
                        }
                    }
                }
                // 아래
                flag = true;
                for (int k = 1; k <= 4; k++) {
                    if (i+k < 19) {
                        if (arr[i+k][j] != 2) {
                            flag = false;
                            break;
                        }
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (i+5 < 19) {
                        if (arr[i+5][j] != 2) {
                            if (i-1 >= 0) {
                                if (arr[i-1][j] != 2) {
                                    cout << 2 << endl << i+1 << ' ' << j+1;
                                    return 0;
                                }
                            }
                            else {
                                cout << 2 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                    }
                    else {
                        if (i-1 >= 0) {
                            if (arr[i-1][j] != 2) {
                                cout << 2 << endl << i+1 << ' ' << j+1;
                                return 0;
                            }
                        }
                        else {
                            cout << 2 << endl << i+1 << ' ' << j+1;
                            return 0;
                        }
                    }
                }

            }
        }
    }
    
    if (!check) {
        cout << 0;
    }
    
}
