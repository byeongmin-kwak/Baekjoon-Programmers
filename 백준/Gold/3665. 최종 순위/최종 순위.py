from collections import deque

T = int(input())

while T > 0:
    n = int(input())
    rank = list(map(int, input().split()))
    
    graph = [[False] * (n + 1) for _ in range(n + 1)]
    indegree = [0] * (n + 1)
    
    for i in range(n):
        for j in range(i+1, n):
            graph[rank[i]][rank[j]] = True
            indegree[rank[j]] += 1
    
    m = int(input())
    for _ in range(m):
        a, b = map(int, input().split())
        if graph[a][b]:
            graph[a][b] = False
            graph[b][a] = True
            indegree[b] -= 1
            indegree[a] += 1
        else:
            graph[a][b] = True
            graph[b][a] = False
            indegree[b] += 1
            indegree[a] -= 1
    
    q = deque()
    for i in range(1, n + 1):
        if indegree[i] == 0:
            q.append(i)
        
    result = []
    
    for _ in range(n):
        if len(q) == 0:
            result = ["IMPOSSIBLE"]
            break
        if len(q) > 1:
            result = ["?"]
            break
        
        now = q.popleft()
        result.append(now)
        
        for next in range(1, n + 1):
            if graph[now][next]:
                indegree[next] -= 1
                if indegree[next] == 0:
                    q.append(next)
                    
    T -= 1
    print(" ".join(map(str, result)))
    
