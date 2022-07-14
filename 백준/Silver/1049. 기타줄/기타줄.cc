#include <iostream>
using namespace std;

int main() {
	
	int N, M;
	cin >> N >> M;

	int min1 = 1001;
	int min2 = 1001;
	int a, b;
	while (M--) {
		cin >> a >> b;
		if (a < min1) {
			min1 = a;
		}
		if (b < min2) {
			min2 = b;
		}
	}

	if (min2*6 < min1) {
		cout << min2 * N;
	}
	else {
		if (N % 6 != 0) {
			cout << min((N / 6 + 1) * min1, (N / 6) * min1 + (N % 6) * min2);
		}
		else {
			cout << (N / 6) * min1;
		}
	}
}