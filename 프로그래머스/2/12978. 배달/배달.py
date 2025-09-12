import heapq

def solution(N, road, K):
    answer = 0

    new_road = [[] for _ in range(N+1)]
    for a, b, c in road:
        new_road[a].append((b, c))
        new_road[b].append((a, c))

    dist = [float('inf')] * (N+1)
    dist[1] = 0  

    heap = [(0, 1)]

    while heap:
        current_dist, current = heapq.heappop(heap)

        if current_dist > dist[current]:
            continue

        for next, plus_time in new_road[current]:
            new_dist = current_dist + plus_time
            if new_dist < dist[next]:
                dist[next] = new_dist
                heapq.heappush(heap, (new_dist, next))

    for d in dist:
        if (d <= K):
            answer += 1
    
    return answer