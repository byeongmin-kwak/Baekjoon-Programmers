#include <bits/stdc++.h>

using namespace std;

int N, M;
string arr[1000], result;
int alphabet[26];
int cnt;

int main() {
    
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < M; i++) {
        int maxCnt = 0, maxIndex = 0;
        for (int j = 0; j < N; j++) {
            int tmp = arr[j][i] - 65;
            alphabet[tmp]++;

            if (maxCnt < alphabet[tmp]) {
                maxCnt = alphabet[tmp];
                maxIndex = tmp;
            }
            else {
                if (maxCnt == alphabet[tmp] && maxIndex > tmp) {
                    maxIndex = tmp;
                }
                cnt++;
            }
        }
        char tmp = maxIndex+65;
        result += tmp;

        for (int j = 0; j < 26; j++) {
            alphabet[j] = 0;
        }
    }
    
    cout << result << endl << cnt << endl;
    
}
