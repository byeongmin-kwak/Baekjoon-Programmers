from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
max_length = 0

def dfs(y, x, mask, length):
    global max_length
    max_length = max(max_length, length)
    
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        
        if 0 <= ny < R and 0 <= nx < C:
            next_bit = 1 << (ord(board[ny][nx]) - 65)
            if (mask & next_bit) == 0:
                dfs(ny, nx, mask | next_bit, length + 1)
        
R, C = map(int, input().split())

board = []

for r in range(R):
    row = input()
    board.append(list(row))

start_mask = 1 << (ord(board[0][0]) - 65)
dfs(0, 0, start_mask, 1)
print(max_length)