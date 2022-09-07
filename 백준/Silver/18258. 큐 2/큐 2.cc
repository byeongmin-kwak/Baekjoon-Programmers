#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0); 
	cin.sync_with_stdio(0);
	
	queue<int> q;

	int n;
	cin >> n;

	int num;
	string command;
	while(n--) {
		cin >> command;

		if (command == "push") {
			cin >> num;
			q.push(num);
		}
		else if (command == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (command == "size") {
			cout << q.size() << '\n';
		}
		else if (command == "empty") {
			if (q.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (command == "front") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
			}
		}
		else if (command == "back") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.back() << '\n';
			}
		}
	}
}