#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
    cin >> T;
    
    int N;
    while(T--) {
        cin >> N;
        int arr[5] = {0,0,0,0,0};
        
        while (N != 0) {
            if (N > 35) {
                if (N >= 60) {
                    arr[0] += N / 60;
                    N %= 60;
                }
                else {
                    arr[0]++;
                    N -= 60;
                }
            }
            else {
                if (N > 5) {
                    if (N >= 10) {
                        arr[1] += N / 10;
                        N %= 10;
                    }
                    else {
                        arr[1]++;
                        N -= 10;
                    }
                }
                else if (N > 0) {
                    arr[3] += N;
                    N = 0;
                }
                else {
                    if (N < -5) {
                        if (N <= -10) {
                            arr[2] += N / -10;
                            N %= 10;
                        }
                        else {
                            arr[2]++;
                            N += 10;
                        }
                    }
                    else {
                        arr[4] -= N;
                        N = 0;
                    }
                }
            }
        }
        
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
}
