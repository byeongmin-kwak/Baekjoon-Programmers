#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
bool visited[100001];
int order[100001];
int N;
int answer = 1;
int idx = 1;


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

void dfs(int current) {
  
  if (visited[current] || answer == 0) {
    return;
  }
  visited[current] = true;
  
  if (order[current] != idx) {
    answer = 0;
    return;
  }
  idx++;
  
  for (int i = 0; i < graph[current].size(); i++) {
    dfs(graph[current][i]);
  }
  
}

int main() {
  
  input();
  
  for (int i = 1; i <= N; i++) {
    sort(graph[i].begin(), graph[i].end(), compare);
  }

  dfs(1);
  
  cout << answer;
  
}
