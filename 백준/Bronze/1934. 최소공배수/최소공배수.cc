#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int T;
	cin >> T;

	int a, b;
	while (T--) {
		cin >> a >> b;

		int x = max(a, b);
		int i = 0;
		while (true) {
			i++;
			int y = x * i;
			if (y % min(a, b) == 0) {
				cout << y << '\n';
				break;
			}
		}
	}

}