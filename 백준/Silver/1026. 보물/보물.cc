#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	int N;
	cin >> N;

	vector<int> v1;
	vector<int> v2;

	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		v1.push_back(a);
	}

	int b;
	for (int i = 0; i < N; i++) {
		cin >> b;
		v2.push_back(b);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int result = 0;
	for (int i = 0; i < N; i++) {
		result += v1[i] * v2[v2.size() - i - 1];
	}
	cout << result;
}