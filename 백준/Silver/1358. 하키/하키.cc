#include <iostream>
using namespace std;

int main() {
	
	int w, h, x, y, p;
	cin >> w >> h >> x >> y >> p;
	int a, b;
	int result = 0;

	while (p--) {
		cin >> a >> b;

		if ((a >= x and a <= x + w) and (b >= y and b <= y + h)) {
			result++;
		}
		else if ((a - x) * (a - x) + (b - (y + h / 2)) * (b - (y + h / 2)) <= (h / 2) * (h / 2)) {
			result++;
		}
		else if ((a - (x+w)) * (a - (x+w)) + (b - (y + h / 2)) * (b - (y + h / 2)) <= (h / 2) * (h / 2)) {
			result++;
		}
	}

	cout << result;

}