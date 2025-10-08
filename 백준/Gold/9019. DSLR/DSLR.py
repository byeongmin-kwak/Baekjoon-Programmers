import sys
input = sys.stdin.readline
from collections import deque

def bfs(A, B):
    q = deque()
    visited = [None] * 10000
    q.append(A)
    visited[A] = ('', -1)
    
    while q:
        current = q.popleft()
        
        if current == B:
            break

        next = (current * 2) % 10000
        if visited[next] is None:
            visited[next] = ('D', current)
            q.append(next)
        
        next = (current - 1) % 10000
        if visited[next] is None:
            visited[next] = ('S', current)
            q.append(next)
        
        next = (current % 1000) * 10 + (current // 1000)
        if visited[next] is None:
            visited[next] = ('L', current)
            q.append(next)
        
        next = (current % 10) * 1000 + (current // 10) 
        if visited[next] is None:
            visited[next] = ('R', current)
            q.append(next)
            
    result = []
    current = B
    while visited[current][1] != -1:
        result.append(visited[current][0])
        current = visited[current][1]
    result = result[::-1]
    return ''.join(result)

T = int(input())

for _ in range(T):
    A, B = map(int, input().split())
    
    print(bfs(A, B))
