#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, X;
vector<vector<int>> city(300001);
bool visited[300001];
vector<int> answer;

int main() {
  
  cin >> N >> M >> K >> X;
  
  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    city[a].push_back(b);
  }
  
  queue<pair<int,int>> que;
  que.push({X,0});
  visited[X] = true;
  
  while(!que.empty()) {
    int tmp = que.front().first;
    int cnt = que.front().second;
    que.pop();
    if (cnt == K) {
      answer.push_back(tmp);
      continue;
    }
    
    for (int elem : city[tmp]) {
      if (!visited[elem]) {
        que.push({elem,cnt+1});
        visited[elem] = true;
      }
    }
  }
  
  if (answer.size() == 0) {
    cout << -1;
  }
  else {
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++) {
      cout << answer[i] << '\n';
    }
  }
  
}
