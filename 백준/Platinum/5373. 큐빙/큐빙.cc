#include <bits/stdc++.h>

using namespace std;

char cube[6][3][3];
char color[6] = {'w','y','r','o','g','b'};


// 0:위, 1:아래, 2:앞, 3:뒤, 4:좌, 5:우
void sol(string command) {
    
    if (command == "U+") {
        char tmp1 = cube[3][0][0];
        char tmp2 = cube[3][0][1];
        char tmp3 = cube[3][0][2];
        
        for (int i = 0; i < 3; i++) {
            cube[3][0][i] = cube[4][0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[4][0][i] = cube[2][0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[2][0][i] = cube[5][0][i];
        }
        cube[5][0][0] = tmp1;
        cube[5][0][1] = tmp2;
        cube[5][0][2] = tmp3;
        
        char tmp = cube[0][0][0];
        cube[0][0][0] = cube[0][2][0];
        cube[0][2][0] = cube[0][2][2];
        cube[0][2][2] = cube[0][0][2];
        cube[0][0][2] = tmp;
        
        tmp = cube[0][0][1];
        cube[0][0][1] = cube[0][1][0];
        cube[0][1][0] = cube[0][2][1];
        cube[0][2][1] = cube[0][1][2];
        cube[0][1][2] = tmp;
    }
    else if (command == "U-") {
        char tmp1 = cube[3][0][0];
        char tmp2 = cube[3][0][1];
        char tmp3 = cube[3][0][2];
        
        for (int i = 0; i < 3; i++) {
            cube[3][0][i] = cube[5][0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[5][0][i] = cube[2][0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[2][0][i] = cube[4][0][i];
        }
        cube[4][0][0] = tmp1;
        cube[4][0][1] = tmp2;
        cube[4][0][2] = tmp3;
        
        char tmp = cube[0][0][0];
        cube[0][0][0] = cube[0][0][2];
        cube[0][0][2] = cube[0][2][2];
        cube[0][2][2] = cube[0][2][0];
        cube[0][2][0] = tmp;
        
        tmp = cube[0][0][1];
        cube[0][0][1] = cube[0][1][2];
        cube[0][1][2] = cube[0][2][1];
        cube[0][2][1] = cube[0][1][0];
        cube[0][1][0] = tmp;
    }
    else if (command == "D+") {
        char tmp1 = cube[3][2][0];
        char tmp2 = cube[3][2][1];
        char tmp3 = cube[3][2][2];
    
        for (int i = 0; i < 3; i++) {
            cube[3][2][i] = cube[5][2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[5][2][i] = cube[2][2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[2][2][i] = cube[4][2][i];
        }
        cube[4][2][0] = tmp1;
        cube[4][2][1] = tmp2;
        cube[4][2][2] = tmp3;
        
        char tmp = cube[1][0][0];
        cube[1][0][0] = cube[1][2][0];
        cube[1][2][0] = cube[1][2][2];
        cube[1][2][2] = cube[1][0][2];
        cube[1][0][2] = tmp;
        
        tmp = cube[1][0][1];
        cube[1][0][1] = cube[1][1][0];
        cube[1][1][0] = cube[1][2][1];
        cube[1][2][1] = cube[1][1][2];
        cube[1][1][2] = tmp;

    }
    else if (command == "D-") {
        char tmp1 = cube[3][2][0];
        char tmp2 = cube[3][2][1];
        char tmp3 = cube[3][2][2];
        
        for (int i = 0; i < 3; i++) {
            cube[3][2][i] = cube[4][2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[4][2][i] = cube[2][2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[2][2][i] = cube[5][2][i];
        }
        cube[5][2][0] = tmp1;
        cube[5][2][1] = tmp2;
        cube[5][2][2] = tmp3;
        
        char tmp = cube[1][0][0];
        cube[1][0][0] = cube[1][0][2];
        cube[1][0][2] = cube[1][2][2];
        cube[1][2][2] = cube[1][2][0];
        cube[1][2][0] = tmp;
        
        tmp = cube[1][0][1];
        cube[1][0][1] = cube[1][1][2];
        cube[1][1][2] = cube[1][2][1];
        cube[1][2][1] = cube[1][1][0];
        cube[1][1][0] = tmp;
    }
    else if (command == "F+") {
        char tmp1 = cube[0][2][0];
        char tmp2 = cube[0][2][1];
        char tmp3 = cube[0][2][2];
        
        for (int i = 0; i < 3; i++) {
            cube[0][2][2-i] = cube[4][i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[4][i][2] = cube[1][0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[1][0][2-i] = cube[5][i][0];
        }
        cube[5][0][0] = tmp1;
        cube[5][1][0] = tmp2;
        cube[5][2][0] = tmp3;
        
        char tmp = cube[2][0][0];
        cube[2][0][0] = cube[2][2][0];
        cube[2][2][0] = cube[2][2][2];
        cube[2][2][2] = cube[2][0][2];
        cube[2][0][2] = tmp;
        
        tmp = cube[2][0][1];
        cube[2][0][1] = cube[2][1][0];
        cube[2][1][0] = cube[2][2][1];
        cube[2][2][1] = cube[2][1][2];
        cube[2][1][2] = tmp;
    }
    else if (command == "F-") {
        char tmp1 = cube[0][2][0];
        char tmp2 = cube[0][2][1];
        char tmp3 = cube[0][2][2];
        
        for (int i = 0; i < 3; i++) {
            cube[0][2][i] = cube[5][i][0];
        }
        for (int i = 0; i < 3; i++) {
            cube[5][2-i][0] = cube[1][0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[1][0][i] = cube[4][i][2];
        }
        cube[4][2][2] = tmp1;
        cube[4][1][2] = tmp2;
        cube[4][0][2] = tmp3;
        
        char tmp = cube[2][0][0];
        cube[2][0][0] = cube[2][0][2];
        cube[2][0][2] = cube[2][2][2];
        cube[2][2][2] = cube[2][2][0];
        cube[2][2][0] = tmp;
        
        tmp = cube[2][0][1];
        cube[2][0][1] = cube[2][1][2];
        cube[2][1][2] = cube[2][2][1];
        cube[2][2][1] = cube[2][1][0];
        cube[2][1][0] = tmp;
    }
    else if (command == "B+") {
        char tmp1 = cube[0][0][0];
        char tmp2 = cube[0][0][1];
        char tmp3 = cube[0][0][2];
        
        for (int i = 0; i < 3; i++) {
            cube[0][0][i] = cube[5][i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[5][i][2] = cube[1][2][2-i];
        }
        for (int i = 0; i < 3; i++) {
            cube[1][2][2-i] = cube[4][2-i][0];
        }
        cube[4][2][0] = tmp1;
        cube[4][1][0] = tmp2;
        cube[4][0][0] = tmp3;
        
        char tmp = cube[3][0][0];
        cube[3][0][0] = cube[3][2][0];
        cube[3][2][0] = cube[3][2][2];
        cube[3][2][2] = cube[3][0][2];
        cube[3][0][2] = tmp;
        
        tmp = cube[3][0][1];
        cube[3][0][1] = cube[3][1][0];
        cube[3][1][0] = cube[3][2][1];
        cube[3][2][1] = cube[3][1][2];
        cube[3][1][2] = tmp;
    }
    else if (command == "B-") {
        char tmp1 = cube[0][0][0];
        char tmp2 = cube[0][0][1];
        char tmp3 = cube[0][0][2];
        
        for (int i = 0; i < 3; i++) {
            cube[0][0][i] = cube[4][2-i][0];
        }
        for (int i = 0; i < 3; i++) {
            cube[4][2-i][0] = cube[1][2][2-i];
        }
        for (int i = 0; i < 3; i++) {
            cube[1][2][2-i] = cube[5][i][2];
        }
        cube[5][0][2] = tmp1;
        cube[5][1][2] = tmp2;
        cube[5][2][2] = tmp3;
        
        char tmp = cube[3][0][0];
        cube[3][0][0] = cube[3][0][2];
        cube[3][0][2] = cube[3][2][2];
        cube[3][2][2] = cube[3][2][0];
        cube[3][2][0] = tmp;
        
        tmp = cube[3][0][1];
        cube[3][0][1] = cube[3][1][2];
        cube[3][1][2] = cube[3][2][1];
        cube[3][2][1] = cube[3][1][0];
        cube[3][1][0] = tmp;
    }
    else if (command == "L+") {
        char tmp1 = cube[0][0][0];
        char tmp2 = cube[0][1][0];
        char tmp3 = cube[0][2][0];
        
        for (int i = 0; i < 3; i++) {
            cube[0][i][0] = cube[3][2-i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[3][2-i][2] = cube[1][i][0];
        }
        for (int i = 0; i < 3;  i++) {
            cube[1][i][0] = cube[2][i][0];
        }
        cube[2][0][0] = tmp1;
        cube[2][1][0] = tmp2;
        cube[2][2][0] = tmp3;
        
        char tmp = cube[4][0][0];
        cube[4][0][0] = cube[4][2][0];
        cube[4][2][0] = cube[4][2][2];
        cube[4][2][2] = cube[4][0][2];
        cube[4][0][2] = tmp;
        
        tmp = cube[4][0][1];
        cube[4][0][1] = cube[4][1][0];
        cube[4][1][0] = cube[4][2][1];
        cube[4][2][1] = cube[4][1][2];
        cube[4][1][2] = tmp;
    }
    else if (command == "L-") {
        char tmp1 = cube[0][0][0];
        char tmp2 = cube[0][1][0];
        char tmp3 = cube[0][2][0];
        
        for (int i = 0; i < 3; i++) {
            cube[0][i][0] = cube[2][i][0];
        }
        for (int i = 0; i < 3; i++) {
            cube[2][i][0] = cube[1][i][0];
        }
        for (int i = 0; i < 3; i++) {
            cube[1][i][0] = cube[3][2-i][2];
        }
        cube[3][2][2] = tmp1;
        cube[3][1][2] = tmp2;
        cube[3][0][2] = tmp3;
        
        char tmp = cube[4][0][0];
        cube[4][0][0] = cube[4][0][2];
        cube[4][0][2] = cube[4][2][2];
        cube[4][2][2] = cube[4][2][0];
        cube[4][2][0] = tmp;
        
        tmp = cube[4][0][1];
        cube[4][0][1] = cube[4][1][2];
        cube[4][1][2] = cube[4][2][1];
        cube[4][2][1] = cube[4][1][0];
        cube[4][1][0] = tmp;
    }
    else if (command == "R+") {
        char tmp1 = cube[0][0][2];
        char tmp2 = cube[0][1][2];
        char tmp3 = cube[0][2][2];
        
        for (int i = 0; i < 3; i++) {
            cube[0][i][2] = cube[2][i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[2][i][2] = cube[1][i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[1][i][2] = cube[3][2-i][0];
        }
        cube[3][2][0] = tmp1;
        cube[3][1][0] = tmp2;
        cube[3][0][0] = tmp3;
        
        char tmp = cube[5][0][0];
        cube[5][0][0] = cube[5][2][0];
        cube[5][2][0] = cube[5][2][2];
        cube[5][2][2] = cube[5][0][2];
        cube[5][0][2] = tmp;
        
        tmp = cube[5][0][1];
        cube[5][0][1] = cube[5][1][0];
        cube[5][1][0] = cube[5][2][1];
        cube[5][2][1] = cube[5][1][2];
        cube[5][1][2] = tmp;
    }
    else {
        char tmp1 = cube[0][0][2];
        char tmp2 = cube[0][1][2];
        char tmp3 = cube[0][2][2];
        
        for (int i = 0; i < 3; i++) {
            cube[0][i][2] = cube[3][2-i][0];
        }
        for (int i = 0; i < 3; i++) {
            cube[3][2-i][0] = cube[1][i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[1][i][2] = cube[2][i][2];
        }
        cube[2][0][2] = tmp1;
        cube[2][1][2] = tmp2;
        cube[2][2][2] = tmp3;
        
        char tmp = cube[5][0][0];
        cube[5][0][0] = cube[5][0][2];
        cube[5][0][2] = cube[5][2][2];
        cube[5][2][2] = cube[5][2][0];
        cube[5][2][0] = tmp;
        
        tmp = cube[5][0][1];
        cube[5][0][1] = cube[5][1][2];
        cube[5][1][2] = cube[5][2][1];
        cube[5][2][1] = cube[5][1][0];
        cube[5][1][0] = tmp;
    }
}

int main() {
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = color[i];
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            string command;
            cin >> command;
            
            sol(command);
            
        }
        

        
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << cube[0][i][j];
            }
            cout << '\n';
        }
    }
}
