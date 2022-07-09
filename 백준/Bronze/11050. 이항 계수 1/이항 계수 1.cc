#include <iostream>
using namespace std;

int main() {

	int N, K;
	cin >> N >> K;

	int a = N;
	for (int i = 1; i < N; i++) {
		a *= N - i;
	}
	if (a == 0) {
		a = 1;
	}
	
	int b = K;
	for (int i = 1; i < K; i++) {
		b *= K - i;
	}
	if (b == 0) {
		b = 1;
	}

	int c = N - K;
	for (int i = 1; i < N - K; i++) {
		c *= N - K - i;
	}
	if (c == 0) {
		c = 1;
	}



	cout << a / (b * c);
}