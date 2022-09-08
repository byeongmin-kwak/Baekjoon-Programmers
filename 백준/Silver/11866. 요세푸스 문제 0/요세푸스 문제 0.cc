#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0); 
	cin.sync_with_stdio(0);
	
	int n, k;
	cin >> n >> k;
	
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";

	while (q.size() != 0) {
		for (int i = 1; i < k; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		
		if (!q.empty()) {
			cout << ", ";
		}

	}
	cout << ">";
}