from collections import deque

def bfs(campus, y, x, visited, answer):
    queue = deque([(y, x)])
    visited[y][x] = True
    
    while queue:
        y, x = queue.popleft()
        
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            
            if ny >= 0 and ny < N and nx >= 0 and nx < M:
                if not visited[ny][nx] and campus[ny][nx] != 'X':
                    visited[ny][nx] = True
                    queue.append((ny, nx))
                    
                    if campus[ny][nx] == 'P':
                        answer[0] += 1
    
    return

N, M  = map(int, input().split())
campus = [list(input()) for _ in range(N)]

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]
visited = [[False] * M for _ in range(N)]
answer = [0]
y = 0
x = 0

for i in range(N):
    for j in range(M):
        if campus[i][j] == 'I':
            y = i
            x = j
        
bfs(campus, y, x, visited, answer)

if answer[0] == 0:
    print("TT")
else:
    print(answer[0])