#include <iostream>
#define MAX 8
using namespace std;

int n, m;
int arr[MAX];

void dfs(int num, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else {
		for (int i = num; i <= n; i++) {
			arr[cnt] = i;
			dfs(i, cnt + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(1, 0);
}