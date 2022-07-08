#include <iostream>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	int a;
	int min = 1000000;
	int max = 0;
	while (n--) {
		cin >> a;

		if (a > max) {
			max = a;
		}

		if (a < min) {
			min = a;
		}
	}

	cout << max * min;
}