#include <bits/stdc++.h>

using namespace std;

int sum[1025][1025];

int main() {
  	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, m;
    cin >> n >> m;

    int num, tmp = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num;
            tmp += num;
            sum[i][j] = tmp;
        }
    }

    int x1, x2, y1, y2;

    while(m--) {
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for (int i = x1; i <= x2; i++) {
            if (y1 == 1) {
                ans += sum[i][y2] - sum[i-1][n];
            }
            else {
                ans += sum[i][y2] - sum[i][y1-1];
            }
        }

        cout << ans << '\n';
    }

}