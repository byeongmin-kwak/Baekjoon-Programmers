#include <bits/stdc++.h>

using namespace std;

char chess[2001][2001];
int N, M, K;
int black[2001][2001];
int white[2001][2001];
int sumBlack[2001][2001];
int sumWhite[2001][2001];

void makeBlackWhite() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if ((i+j) % 2 == 0) {
                if (chess[i][j] == 'B') {
                    white[i][j] = 1;
                }
                else {
                    black[i][j] = 1;
                }
            }
            else {
                if (chess[i][j] == 'W') {
                    white[i][j] = 1;
                }
                else {
                    black[i][j] = 1;
                }
            }
        }
    }
}

void makeSumBlack() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            sumBlack[i][j] = sumBlack[i][j-1] + black[i][j];
        }
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 2; j <= N; j++) {
            sumBlack[j][i] = sumBlack[j-1][i] + sumBlack[j][i];
        }
    }
}

void makeSumWhite() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            sumWhite[i][j] = sumWhite[i][j-1] + white[i][j];
        }
    }
    
    for (int i = 1; i <= M; i++) {
        for (int j = 2; j <= N; j++) {
            sumWhite[j][i] = sumWhite[j-1][i] + sumWhite[j][i];
        }
    }
}

int main() {
    
    cin >> N >> M >> K;
    
    string s;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int j = 1; j <= M; j++) {
            chess[i][j] = s[j-1];
        }
    }
    
    
    makeBlackWhite();
    makeSumBlack();
    makeSumWhite();
    
    int ans = 10000000;
    
    for (int i = K; i <= N; i++) {
        for (int j = K; j <= M; j++) {
            ans = min(ans, sumBlack[i][j] - sumBlack[i][j-K] - sumBlack[i-K][j] + sumBlack[i-K][j-K]);
            ans = min(ans, sumWhite[i][j] - sumWhite[i][j-K] - sumWhite[i-K][j] + sumWhite[i-K][j-K]);
            
        }
    }
    
    cout << ans << '\n';
    


}
