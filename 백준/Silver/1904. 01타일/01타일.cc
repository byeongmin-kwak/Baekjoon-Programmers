#include <bits/stdc++.h>
using namespace std;

int N;
long long arr[1000001];

long long dp(int x) {
	if (x == 0) {
		arr[x] = 0;
		return arr[x];
	}
	else if (x == 1) {
		arr[x] = 1;
		return arr[x];
	}
	else if (x == 2) {
		arr[x] = 2;
		return arr[x];
	}
	if (arr[x] != 0) {
		return arr[x];
	}
	else {
		arr[x] = (dp(x - 1) + dp(x - 2)) % 15746;
		return arr[x];
	}
}


int main() {
	cin >> N;

	cout << dp(N);
}