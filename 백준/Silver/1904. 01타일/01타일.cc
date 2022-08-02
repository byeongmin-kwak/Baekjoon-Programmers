#include <bits/stdc++.h>
using namespace std;

int N;
long long arr[1000001];

long long dp(int x) {
	for (int i = 3; i <= N; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	}
	return arr[x];
}


int main() {
	cin >> N;

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;

	cout << dp(N);
}