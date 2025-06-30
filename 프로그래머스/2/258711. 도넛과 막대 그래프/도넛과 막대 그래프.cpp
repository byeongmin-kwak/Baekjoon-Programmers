#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> newEdges(1000000);
int maxIdx = 1000000;

// 자신에게 들어오는 edge가 없고, 나가는 edge가 2개 이상이 것
int findNewVertex() {
    
    vector<bool> check(1000000);
    
    // 나가는 edge가 2개 이상인 것 확인
    for (int i = 1; i <= 1000000; i++) {
        if (newEdges[i].size() == 0) {
            maxIdx = i - 1;
        }
        if (newEdges[i].size() >= 2) check[i] = true;
    }

    // 들어오는 edge가 없는거 확인
    for (int i = 1; i <= 1000000; i++) {
        if (newEdges[i].size() == 0) {
            maxIdx = i - 1;
        }
        
        for (int v : newEdges[i]) {
            check[v] = false;
        }
    }
    
    for (int i = 1; i <= maxIdx; i++) {
        if (check[i]) return i;
    }
    return - 1;
}

// 아래와 같은 형태로 edge변경
// 1 : 2, 3
// 2 : 4
void makeNewEdges(vector<vector<int>>& edges) {
    for (int i = 0; i < edges.size(); i++) {
        newEdges[edges[i][0]].push_back(edges[i][1]);
    }
}

int checkType(int start) {
    
    queue<int> que;
    vector<bool> visited(1000000);
    
    que.push(start);
    
    while (!que.empty()) {
        int now = que.front();
        que.pop();
                
        visited[now] = true;
        
        if (newEdges[now].size() == 0) {
            return 2;
        }
        
        if (newEdges[now].size() == 2) {
            return 3;
        }
        
        for (int v : newEdges[now]) {
            if (!visited[v]) {
                que.push(v);
            }
        }   
    }
    
    return 1;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    
    makeNewEdges(edges);
    
    int newVertex = findNewVertex();
    answer[0] = newVertex;
    
    for (int v : newEdges[newVertex]) {
        answer[checkType(v)]++;
    }
    
    return answer;
}