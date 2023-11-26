#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> node[20001];
bool visited[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int distance = -1;
    
    for (int i = 0; i < edge.size(); i++) {
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }
    
    queue<pair<int, int>> que;
    
    que.push({1, 0});
    visited[1] = true;
    
    while(!que.empty()) {
        int current = que.front().first;
        int dis = que.front().second;
        que.pop();
        
        if (dis == distance) {
            answer++;
        }
        else if (dis > distance) {
            distance = dis;
            answer = 1;
        }
        
        for (int i = 0; i < node[current].size(); i++) {
            if (!visited[node[current][i]]) {
                visited[node[current][i]] = true;
                que.push({node[current][i], dis+1});
            }
        }
    }
    
    return answer;
}