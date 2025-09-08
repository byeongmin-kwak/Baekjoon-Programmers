from collections import deque

def solution(m, n, board):
    answer = 0
    board = [list(row) for row in board]

    while True:
        idx_list = []
        
        # 해당되는 블록의 첫번째 좌표 표시
        for y in range(m-1):
            for x in range(n-1):
                if board[y][x] != '.' and board[y][x] == board[y][x+1] == board[y+1][x] == board[y+1][x+1]:
                    idx_list.append((y, x))
        
        if len(idx_list) == 0:
            break
        
        # 좌표를 기반으로 블록 삭제
        for point in idx_list:
            y, x = point[0], point[1]
            
            board[y][x] = '.'
            board[y+1][x] = '.'
            board[y][x+1] = '.'
            board[y+1][x+1] = '.'
            
        # 삭제된 블록 위에 있는 블록 내려오기
        for x in range(n): 
            queue = deque()
            # 아래에서 위로 탐색
            for y in range(m-1, -1, -1):
                if board[y][x] != '.':
                    queue.append(board[y][x])
            # 다시 아래부터 채우기
            for y in range(m-1, -1, -1):
                if queue:
                    board[y][x] = queue.popleft()
                else:
                    board[y][x] = '.'
        
    
    for y in range(m):
        for x in range(n):
            if board[y][x] == '.':
                answer += 1

    return answer