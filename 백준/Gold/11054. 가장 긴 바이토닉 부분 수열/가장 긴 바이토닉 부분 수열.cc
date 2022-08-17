#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int arr[1001];
	int dp[1001];
	int r_dp[1001];

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i] and dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	for (int i = n; i >= 1; i--) {
		r_dp[i] = 1;
		for (int j = n; j > i; j--) {
			if (arr[i] > arr[j] and r_dp[i] < r_dp[j] + 1) {
				r_dp[i] = r_dp[j] + 1;
			}
		}
	}

	int result = 0;

	for (int i = 1; i <= n; i++) {
		if (result < dp[i] + r_dp[i] - 1) {
			result = dp[i] + r_dp[i] - 1;
		}
	}

	cout << result;

	
}