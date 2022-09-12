#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
		
	int T;
	cin >> T;

	string p;
	int n;
	string x;

	while(T--) {
		cin >> p >> n >> x;
		deque<int> deq;
		string temp;
		for (int i = 1; i < x.size(); i++) {
			if (x[i] == ',' or x[i] == ']') {
				if (!temp.empty()) {
					deq.push_back(stoi(temp));
					temp.clear();
				}
			}
			else {
				temp += x[i];
			}
		}
		
		int check = 0;
		bool reverse = false;
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') {
				if (!deq.empty()) {
					reverse = !reverse;
				}
			}
			else if (p[i] == 'D') {
				if (!deq.empty()) {
					if (reverse) {
						deq.pop_back();
					}
					else {
						deq.pop_front();
					}
				}
				else {
					cout << "error" << '\n';
					check = 1;
					break;
				}
			}
		}
		if (check == 0) {
			cout << '[';
			if (deq.size() >= 1) {
				if (reverse) {
					for (int i = deq.size() - 1; i > 0; i--) {
						cout << deq[i] << ',';
					}
					cout << deq[0] << ']' << '\n';
				}
				else {
					for (int i = 0; i < deq.size()-1; i++) {
						cout << deq[i] << ',';
					}
					cout << deq[deq.size()-1] << ']' << '\n';
				}
			}
			else {
				cout << ']' << '\n';
			}
		}
	}
}