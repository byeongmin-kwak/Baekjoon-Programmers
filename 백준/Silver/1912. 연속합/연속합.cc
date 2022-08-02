#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;

	int arr[100001];
	int dp[100001];

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int M = -1001;

	for (int i = 1; i <= n; i++) {
		if (dp[i - 1] + arr[i] < arr[i]) {
			dp[i] = arr[i];
		}
		else {
			dp[i] = dp[i - 1] + arr[i];
		}

		if (dp[i] > M) {
			M = dp[i];
		}
	}

	cout << M;
}