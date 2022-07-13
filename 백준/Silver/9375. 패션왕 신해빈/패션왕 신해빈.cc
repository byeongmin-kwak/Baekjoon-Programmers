#include <iostream>
#include <map>
using namespace std;


int main() {
	
	int T;
	cin >> T;

	int n;
	while (T--) {
		cin >> n;

		map<string, int> m;
		string s1, s2;
		
		while (n--) {
			cin >> s1 >> s2;

			if (m.find(s2) == m.end()) {
				m.insert({ s2, 1 });
			}
			else {
				m[s2]++;
			}
		}
		int result = 1;

		for (auto i : m) {
			result *= (i.second + 1);
		}
		result -= 1;
		cout << result << '\n';
	}
}