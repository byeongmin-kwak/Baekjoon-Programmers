from collections import deque

def solve(i, j):
    result = 0
    visited = [False] * (N+1)
    
    q = deque()
    q.append((i, 0))
    visited[i] = True
    
    while q:
        node, dist = q.popleft()
        
        if node == j:
            result = dist
            break
        
        for next_node in graph[node]:
            if not visited[next_node]:
                visited[next_node] = True
                q.append((next_node, dist + 1))
        
    return result

N, M = map(int, input().split())

graph = [[] for _ in range(N+1)]

for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    
answer = [0, float('inf')]

for i in range(1, N+1):
    total = 0
    for j in range(1, N+1):
        if i == j:
            continue
        total += solve(i, j)
    if total < answer[1]:
        answer[0] = i
        answer[1] = total
        
print(answer[0])