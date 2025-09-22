def solution(board):
    n, m = len(board), len(board[0])
    dp = [[0] * m for _ in range(n)]
    answer = 0

    for y in range(n):
        for x in range(m):
            if board[y][x] == 1:
                if y == 0 or x == 0: 
                    dp[y][x] = 1
                else:
                    dp[y][x] = min(dp[y-1][x], dp[y][x-1], dp[y-1][x-1]) + 1
                answer = max(answer, dp[y][x])
    
    return answer * answer
