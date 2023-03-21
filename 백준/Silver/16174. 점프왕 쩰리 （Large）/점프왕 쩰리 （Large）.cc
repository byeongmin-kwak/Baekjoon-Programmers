#include <iostream>
#include <queue>
using namespace std;

int N;
int space[64][64];
bool check[64][64];

void game() {
	queue<pair<int, int>> q;

	q.push({ 0,0 });
	check[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (space[x][y] == -1) {
			cout << "HaruHaru";
			exit(0);
		}
		else if (space[x][y] == 0) continue;

		if (y + space[x][y] < N && !check[x][y + space[x][y]]) {
			q.push({ x, y + space[x][y] });
			check[x][y + space[x][y]] = true;
		}
		if (x + space[x][y] < N && !check[x + space[x][y]][y]) {
			q.push({ x + space[x][y], y });
			check[x + space[x][y]][y] = true;
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> space[i][j];
	
	game();

	cout << "Hing";

	return 0;
}