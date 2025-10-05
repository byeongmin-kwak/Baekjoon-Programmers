from collections import deque

N, M = map(int, input().split())

graph = [[] for _ in range(N + 1)]
indegree = [0] * (N + 1)
result = []

for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1

que = deque()

for i in range(1, N + 1):
    if indegree[i] == 0:
        que.append(i)

while que:
    now = que.popleft()
    result.append(now)
    for i in graph[now]:
        indegree[i] -= 1
        if indegree[i] == 0:
            que.append(i)
            
print(' '.join(map(str, result)))
