from collections import deque

def bfs(start, cut_a, cut_b, new_wires, n):
    visited = [False] * (n+1)
    visited[start] = True
    q = deque([start])
    count = 1
    
    while q:
        node = q.popleft()
        for nxt in new_wires[node]:
            if visited[nxt]:
                continue
            
            if (node == cut_a and nxt == cut_b) or (node == cut_b and nxt == cut_a):
                continue
            visited[nxt] = True
            q.append(nxt)
            count += 1
    return count

def solution(n, wires):
    new_wires = [[] for _ in range(n+1)]
    for a, b in wires:
        new_wires[a].append(b)
        new_wires[b].append(a)
    
    answer = n
    for a, b in wires:
        count = bfs(1, a, b, new_wires, n)  
        diff = abs(n - 2*count)             
        answer = min(answer, diff)
    
    return answer
