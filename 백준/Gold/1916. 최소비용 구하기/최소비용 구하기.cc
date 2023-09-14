#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> weight[1001];
int dist[1001];
int N, M, Start, End;

int main() {
  
  cin >> N >> M;
  
  int a, b, cost;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> cost;
    weight[a].push_back({cost, b});
  }
  
  cin >> Start >> End;
  
  for (int i = 1; i <= N; i++) {
    dist[i] = 1000000000;
  }
  
  priority_queue<pair<int,int>> pq;
  
  pq.push({0, Start});
  dist[Start] = 0;
  
  while(!pq.empty()) {
    cost = -pq.top().first;
    int current = pq.top().second;
    pq.pop();
    
    if (dist[current] < cost) continue;
    
    for (int i = 0; i < weight[current].size(); i++) {
      int updateCost = cost + weight[current][i].first;
      
      if (updateCost < dist[weight[current][i].second]) {
        dist[weight[current][i].second] = updateCost;
        pq.push({-updateCost, weight[current][i].second});
      }
    }
  }
  
  cout << dist[End];
  
  
}
