#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph(1001);
vector<bool> visited(1001);
int N, M, V;

void DFS(int start) {
  cout << start << ' ';
  for (int elem : graph[start]) {
    if (!visited[elem]) {
      visited[elem] = true;
      DFS(elem);
    }
  }
}

void BFS(int start) {
  queue<int> que;
  que.push(start);
  visited[start] = true;
  
  while(!que.empty()) {
    int tmp = que.front();
    que.pop();
    cout << tmp << ' ';
    
    for (int elem : graph[tmp]) {
      if (!visited[elem]) {
        que.push(elem);
        visited[elem] = true;
      }
    }
  }
}


int main() {
  cin >> N >> M >> V;
  
  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  for (int i = 1; i <= N; i++) {
    sort(graph[i].begin(), graph[i].end());
  }
  
  visited[V] = true;
  DFS(V);
  cout << endl;
  
  for (int i = 1; i <= N; i++) {
    visited[i] = false;
  }
  BFS(V);
}
