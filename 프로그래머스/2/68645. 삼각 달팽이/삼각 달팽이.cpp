#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    int arr[1002][1002];
    
    for (int i = 0; i < n; i++) {
        arr[i][0] = i+1;
        arr[n-1][i] = i+n;
    }
    
    int x = n-1, y = n-1;
    int num = 2*n-1;
    string direction = "top";
    
    bool flag = false;
    if (n >= 3) {
        flag = true;
    }
    while (flag) {
        if (direction == "top") {
            if (arr[y-1][x-1] == 0) {
                arr[y-1][x-1] = num+1;
                y--;
                x--;
                num++;
            }
            else {
                direction = "bottom";
                if (arr[y+1][x] != 0) {
                    break;
                }
            }
        }
        else if (direction == "bottom") {
            if (arr[y+1][x] == 0) {
                arr[y+1][x] = num+1;
                y++;
                num++;
            }
            else {
                direction = "right";
                if (arr[y][x+1] != 0) {
                    break;
                }
            }
        }
        else {
            if (arr[y][x+1] == 0) {
                arr[y][x+1] = num+1;
                x++;
                num++;
            }
            else {
                direction = "top";
                if (arr[y-1][x-1] != 0) {
                    break;
                }
            }
        }
    }
    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            answer.push_back(arr[i][j]);
        }
    }
    
    
    return answer;
}