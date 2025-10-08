from collections import deque

def bfs():
    visited = [False] * 101
    q = deque()
    q.append((1, 0))
    visited[1] = True
    
    while q:
        current, cnt = q.popleft()
        if current == 100:
            return cnt
        
        for i in range(1, 7):
            next = current + i
            if next > 100:
                continue
            
            if next in ladder:
                next = ladder[next]
            elif next in snake:
                next = snake[next]
            
            if not visited[next]:
                visited[next] = True
                q.append((next, cnt + 1))
                    

N, M = map(int, input().split())

ladder = {}
snake = {}

for _ in range(N):
    a, b = map(int, input().split())
    ladder[a] = b
    
for _ in range(M):
    a, b = map(int, input().split())
    snake[a] = b
    
print(bfs())