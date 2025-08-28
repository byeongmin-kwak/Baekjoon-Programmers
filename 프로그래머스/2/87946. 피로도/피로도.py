def dfs(k, dungeons, visited, count):
    max_count = count
    
    for i in range(len(dungeons)):
        need, cost = dungeons[i]
        if not visited[i] and k >= need:
            visited[i] = True
            max_count = max(max_count, dfs(k - cost, dungeons, visited, count + 1))
            visited[i] = False
    
    return max_count


def solution(k, dungeons):
    visited = [False] * len(dungeons)
    return dfs(k, dungeons, visited, 0)
