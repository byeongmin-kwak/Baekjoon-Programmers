#include <string>
#include <vector>

using namespace std;

int answer = 0;    
bool visited[17][17][17];
vector<int> edge[17];


void dfs(vector<int>& info, int current, int sheep, int wolf) {
    answer = max(answer, sheep);
    
    for (int i = 0; i < edge[current].size(); i++) {
        int next = edge[current][i];
        
        if (info[next] == 0) {
            if (!visited[next][sheep+1][wolf]) {
                visited[next][sheep+1][wolf] = true;
                info[next] = -1;
                
                dfs(info, next, sheep+1, wolf);
                
                visited[next][sheep+1][wolf] = false;
                info[next] = 0;
            }
        }
        else if (info[next] == 1) {
            if (!visited[next][sheep][wolf+1] && sheep > wolf+1) {
                visited[next][sheep][wolf+1] = true;
                info[next] = -1;
                
                dfs(info, next, sheep, wolf+1);
                
                visited[next][sheep][wolf+1] = false;
                info[next] = 1;
            }
        }
        else {
            if (!visited[next][sheep][wolf]) {
                visited[next][sheep][wolf]  = true;
                
                dfs(info, next, sheep, wolf);
                
                visited[next][sheep][wolf]  = false;
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    for (int i = 0; i < edges.size(); i++) {
        edge[edges[i][0]].push_back(edges[i][1]);
        edge[edges[i][1]].push_back(edges[i][0]);    
    }
    
    info[0] = -1;
    
    dfs(info, 0, 1, 0);
    
    return answer;
}