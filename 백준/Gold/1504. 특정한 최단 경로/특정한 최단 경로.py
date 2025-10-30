import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

def dijkstra(start):
    distance = [INF] * (N + 1)
    distance[start] = 0
    pq = [(0, start)] 

    while pq:
        dist, now = heapq.heappop(pq)
        if dist > distance[now]:
            continue

        for nxt, cost in graph[now]:
            new_cost = dist + cost
            if new_cost < distance[nxt]:
                distance[nxt] = new_cost
                heapq.heappush(pq, (new_cost, nxt))
    return distance

N, E = map(int, input().split())
graph = [[] for _ in range(N + 1)]

for _ in range(E):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

v1, v2 = map(int, input().split())

dist_from_1 = dijkstra(1)
dist_from_v1 = dijkstra(v1)
dist_from_v2 = dijkstra(v2)

path1 = dist_from_1[v1] + dist_from_v1[v2] + dist_from_v2[N] 
path2 = dist_from_1[v2] + dist_from_v2[v1] + dist_from_v1[N] 

result = min(path1, path2)

print(result if result < INF else -1)
