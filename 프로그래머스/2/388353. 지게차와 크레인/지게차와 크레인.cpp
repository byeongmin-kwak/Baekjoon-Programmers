#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
bool check = false;


void bfs(const vector<string>& storage, int y, int x, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;
    
    while (!q.empty()) {
        auto [cy, cx] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= storage.size() || nx < 0 || nx >= storage[0].size()) {
                continue;
            }

            if (storage[ny][nx] == '0') {
                if (ny == 0 || ny == storage.size() - 1 || nx == 0 || nx == storage[0].size() - 1) {
                    check = true;
                    return;
                }
                if (!visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }
}

int count(const vector<string>& storage) {
    int sum = 0;
    
    for (int y = 0; y < storage.size(); y++) {
        for (int x = 0; x < storage[y].size(); x++) {
            if (storage[y][x] != '0') {
                sum++;
            }
        }
    }
    
    return sum;
}

void solve(string request, vector<string>& storage) {
    
    if (request.size() == 1) {
        for (int y = 0; y < storage.size(); y++) {
            for (int x = 0; x < storage[y].size(); x++) {
                  if (storage[y][x] == request[0]) {
                      if (y == 0 || y == storage.size()-1 || x == 0 || x == storage[y].size()-1) {
                            storage[y][x] = '1';
                            continue;
                      }
                      check = false;
                      vector<vector<bool>> visited(storage.size(), vector<bool>(storage[0].size(), false));
                      bfs(storage, y, x, visited);
                      if (check) {
                          storage[y][x] = '1';
                      }
                    }
                  }  
            }
        
        for (int y = 0; y < storage.size(); y++) {
            for (int x = 0; x < storage[y].size(); x++) {
                if (storage[y][x] == '1') {
                    storage[y][x] = '0';
                }
            }
        }
    
    } else {
        for (int y = 0; y < storage.size(); y++) {
            for (int x = 0; x < storage[y].size(); x++) {
                if (storage[y][x] == request[0]) {
                    storage[y][x] = '0';
                }
            }
        }       
    }
    
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    for (int i = 0; i < requests.size(); i++) {
        solve(requests[i], storage);
    }
    
    answer = count(storage);
    
    return answer;
}