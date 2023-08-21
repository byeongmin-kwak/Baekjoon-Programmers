#include <iostream>

using namespace std;

int arr1[] = {0,1,0,1};
int arr2[] = {0};
int arr3[] = {1};

int main() {
    int A, T, input, answer;
    
    cin >> A >> T >> input;
    
    int cnt = 0;
    int tmp = 0;
    bool flag = false;

    for (int i = 1; i < 10000; i++) {
        for (int j = 0; j < 4; j++) {
            cnt++;
            if (arr1[j] == input) {
                tmp++;
                if (tmp == T) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            break;
        }
        
        for (int j = 0; j < i+1; j++) {
            cnt++;
            if (arr2[0] == input) {
                tmp++;
                if (tmp == T) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            break;
        }
        
        for (int j = 0; j < i+1; j++) {
            cnt++;
            if (arr3[0] == input) {
                tmp++;
                if (tmp == T) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            break;
        }
    }
        
    answer = (cnt-1) % A;
    cout << answer;
    
}
