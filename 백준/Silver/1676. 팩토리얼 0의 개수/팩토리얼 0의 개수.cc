#include <iostream>
#include <string>
using namespace std;


int main() {
	
	int N;
	cin >> N;
	
	int cnt = 0;
	for (int i = 5; i <= N; i *= 5) {
		cnt += N / i;
	}

	cout << cnt;
}