#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> station[3001];
bool circulation[3001];
bool visited[3001];
vector<int> answer;

void checkCirculation(int start, int current, int depth) {
  if (start == current) {
    if (depth > 2) {
      circulation[start] = true;
    }
    else if (depth == 2) {
      visited[start] = false;
      return;
    }
    else if (depth == 1) {
      return;
    }
  }

  for (int i = 0; i < station[current].size(); i++) {
    if (!visited[station[current][i]]) {
      visited[station[current][i]] = true;
      checkCirculation(start, station[current][i], depth+1);
    }
  }
}

void clearVisited() {
  for (int i = 1; i <= N; i++) {
    visited[i] = false;
  }
}

void BFS(int current, int distance) {
  if (circulation[current]) {
    answer.push_back(distance);
    return;
  }
  queue<pair<int, int>> que;
  que.push({current, 0});
  
  while (!que.empty()) {
    current = que.front().first;
    distance = que.front().second;
    que.pop();
    
    for (int i = 0; i < station[current].size(); i++) {
      if (!visited[station[current][i]]) {
        visited[station[current][i]]= true;
        if (circulation[station[current][i]]) {
          answer.push_back(distance+1);
          return;
        }
        else {
          que.push({station[current][i], distance+1});
        }
      }
    }
  }
}

int main() {
  
  cin >> N;
  
  int a, b;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    station[a].push_back(b);
    station[b].push_back(a);
  }
  
  for (int i = 1; i <= N; i++) {
    checkCirculation(i, i, 0);
    clearVisited();
  }
  
  for (int i = 1; i <= N; i++) {
    visited[i] = true;
    BFS(i, 0);
    clearVisited();
  }
  
  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i] << ' ';
  }
}
