#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return GCD(b, a % b);
	}
}

int main() {
	
	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int gcd;
	for (int i = 1; i < N; i++) {
		gcd = GCD(v[0], v[i]);
		cout << v[0] / gcd << '/' << v[i] / gcd << '\n';
	}
}