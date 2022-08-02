#include <bits/stdc++.h>
using namespace std;

long long arr[101] = { 0,1,1, };

long long dp(int x) {
	if (x < 3) {
		return arr[x];
	}
	else if (arr[x] == 0) {
		arr[x] = dp(x-2) + dp(x-3);
		return arr[x];
	}
	else {
		return arr[x];
	}
}


int main() {
	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		
		cout << dp(N) << '\n';
	}
}