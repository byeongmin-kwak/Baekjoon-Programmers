#include <iostream>
using namespace std;


int main() {
	
	long long n, m;
	cin >> n >> m;
	
	long long cnt = 0;
	for (long long i = 5; i <= n; i *= 5) {
		cnt += n / i;
	}
	
	for (long long i = 5; i <= m; i *= 5) {
		cnt -= m / i;
	}

	for (long long i = 5; i <= n-m; i *= 5) {
		cnt -= (n-m) / i;
	}

	long long five = cnt;
	cnt = 0;

	for (long long i = 2; i <= n; i *= 2) {
		cnt += n / i;
	}

	for (long long i = 2; i <= m; i *= 2) {
		cnt -= m / i;
	}

	for (long long i = 2; i <= n - m; i *= 2) {
		cnt -= (n - m) / i;
	}
	long long two = cnt;

	cout << min(five, two);
}