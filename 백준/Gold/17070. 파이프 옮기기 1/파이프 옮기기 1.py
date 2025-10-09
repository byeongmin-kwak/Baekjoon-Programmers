import sys
input = sys.stdin.readline

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

dp = [[[0] * 3 for _ in range(N)] for _ in range(N)]

# 초기 상태: (0,0)-(0,1) 가로로 시작
dp[0][1][0] = 1

for y in range(N):
    for x in range(2, N):  # (0,0)-(0,1) 이미 시작했으므로 x=2부터
        if board[y][x] == 1:
            continue  # 벽이면 불가능

        # 가로
        dp[y][x][0] = dp[y][x-1][0] + dp[y][x-1][2]

        # 세로
        if y > 0:
            dp[y][x][1] = dp[y-1][x][1] + dp[y-1][x][2]

        # 대각선
        if y > 0 and board[y-1][x] == 0 and board[y][x-1] == 0:
            dp[y][x][2] = dp[y-1][x-1][0] + dp[y-1][x-1][1] + dp[y-1][x-1][2]

print(sum(dp[N-1][N-1]))
