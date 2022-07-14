#include <iostream>
#define MAX 9
using namespace std;

int N, M;
int arr[MAX];
bool visited[MAX];

void dfs(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[k] = i;
				dfs(k + 1);
				visited[i] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	dfs(0);
}