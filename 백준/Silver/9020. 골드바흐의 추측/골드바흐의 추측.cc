#include <iostream>
using namespace std;

int main() {
	
	int* array = new int[10001]{};

	for (int i = 2; i <= 10000; i++) {
		array[i] = i;
	}

	for (int i = 2; i * i <= 10000; i++) {
		if (array[i] != 0) {
			for (int j = i * i; j <= 10000; j += i) {
				array[j] = 0;
			}
		}
	}
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int prime;
		cin >> prime;

		int tmp = 0;

		for (int j = prime / 2; j >= 2 / 2; j--) {
			if (tmp == 1) {
				break;
			}
			if (array[j] != 0) {
				for (int k = prime / 2; k <= prime - 2; k++) {
					if (array[k] != 0) {
						if (j + k == prime) {
							cout << j << " " << k << '\n';
							tmp = 1;
							break;
						}
					}
				}
			}
		}
	}
	return 0;
}