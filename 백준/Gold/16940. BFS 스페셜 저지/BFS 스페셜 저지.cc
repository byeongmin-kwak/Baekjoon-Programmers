#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
bool visited[100001];
int order[100001];
int N;


bool compare(int a, int b) {
  
  return order[a] < order[b];
  
}

void input() {
  
  cin >> N;
  
  for (int i = 0; i < N-1; i++) {
    int a, b;
    cin >> a >> b;
    
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  for (int i = 1; i <= N; i++) {
    int tmp;
    cin >> tmp;
    order[tmp] = i;
  }
  
}

void bfs() {
  
  queue<int> que;
  que.push(1);
  visited[1] = true;
  int idx = 2;
  
  while(!que.empty()) {
    int current = que.front();
    que.pop();
    
    for (int i = 0; i < graph[current].size(); i++) {
      if (visited[graph[current][i]]) {
        continue;
      }
      if (order[graph[current][i]] == idx) {
        que.push(graph[current][i]);
        visited[graph[current][i]] = true;
        idx++;
      }
      else {
        cout << "0";
        return;
      }
    }
  }
  
  cout << "1";
  return;
  
}

int main() {
  
  input();
  
  for (int i = 1; i <= N; i++) {
    sort(graph[i].begin(), graph[i].end(), compare);
  }
  
  bfs();
}
