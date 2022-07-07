#include <iostream>
using namespace std;

int main() {
	
	int n, T;
	int enter, departure;
	int x, y, r, x1, y1, x2, y2;

	cin >> T;

	while (T--) {
		cin >> x1 >> y1 >> x2 >> y2;

		cin >> n;

		enter = 0;
		departure = 0;

		while (n--) {
			cin >> x >> y >> r;

			if ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) > r * r) {
				if ((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y) < r * r) {
					enter++;
				}
			}

			else if ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) < r * r) {
				if ((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y) > r * r) {
					departure++;
				}
			}
		}

		cout << enter + departure << '\n';
	}

}