#include <iostream>
#include <vector>
using namespace std;


int main() {

	int T, N, M;

	cin >> T;

	vector<vector<long long >> dp(31, vector<long long>(31, 0));
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= 30; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = 1;
			}
			else if (j == i) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
	}

	while (T--) {
		cin >> N >> M;

		cout << dp[M][N] << '\n';
	}
}