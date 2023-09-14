#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000

using namespace std;

vector<pair<int,int>> graph[20001];
int dist[20001];
int V, E, Start;

int main() {
  
  cin >> V >> E;
  
  cin >> Start;
  
  int a, b, cost;
  for (int i = 0; i < E; i++) {
    cin >> a >> b >> cost;
    graph[a].push_back({cost, b});
  }
  
  
  
  for (int i = 1; i <= V; i++) {
    dist[i] = INF;
  }
  
  priority_queue<pair<int,int>> pq;
  
  pq.push({0, Start});
  dist[Start] = 0;
  
  while(!pq.empty()) {
    cost = -pq.top().first;
    int current = pq.top().second;
    pq.pop();
    
    if (dist[current] < cost) continue;
    
    for (int i = 0; i < graph[current].size(); i++) {
      int updateCost = cost + graph[current][i].first;
      
      if (updateCost < dist[graph[current][i].second]) {
        dist[graph[current][i].second] = updateCost;
        pq.push({-updateCost, graph[current][i].second});
      }
    }
  }
  
  for (int i = 1; i <= V; i++) {
    if (dist[i] == INF) cout << "INF" << '\n';
    else  cout << dist[i] << '\n';
  }
  
}
