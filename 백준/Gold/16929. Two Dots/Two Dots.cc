#include <iostream>

using namespace std;

char arr[50][50];
int N, M;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool answer;
bool visited[50][50];

void dfs(int x, int y, int depth, pair<int,int> start) {
    if (x == start.first && y == start.second && depth >= 4) {
        cout << "Yes";
        exit(0);
    }
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx == start.first && ny == start.second && depth >= 3) {
            dfs(nx, ny, depth+1, {start.first, start.second});
        }
        
        if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[ny][nx]) {
            
            if (arr[ny][nx] == arr[start.second][start.first]) {
                visited[ny][nx] = true;
                dfs(nx, ny, depth+1, {start.first, start.second});
                visited[ny][nx] = false;
            }
        }
    }
}


int main() {

    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            dfs(j, i, 0, {j,i});
            visited[i][j] = false;
        }
    }
    
    cout << "No";
    
}
