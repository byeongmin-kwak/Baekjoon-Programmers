def dfs(y1, x1, y2, x2, house):
    global N
    if y2 == N - 1 and x2 == N - 1:
        global answer
        answer += 1
        return
    
    # 가로 
    if y1 == y2:
        # 가로 이동
        if x2 + 1 < N and house[y2][x2+1] == 0:
            dfs(y2, x2, y2, x2+1, house)
        # 대각선 이동
        if x2 + 1 < N and y2 + 1 < N and house[y2][x2+1] == 0 and house[y2+1][x2] == 0 and house[y2+1][x2+1] == 0:
            dfs(y2, x2, y2+1, x2+1, house)
    # 세로
    elif x1 == x2:
        # 세로 이동
        if y2 + 1 < N and house[y2+1][x2] == 0:
            dfs(y2, x2, y2+1, x2, house)
        # 대각선 이동
        if x2 + 1 < N and y2 + 1 < N and house[y2][x2+1] == 0 and house[y2+1][x2] == 0 and house[y2+1][x2+1] == 0:
            dfs(y2, x2, y2+1, x2+1, house)
    # 대각선
    else:
        # 가로 이동
        if x2 + 1 < N and house[y2][x2+1] == 0:
            dfs(y2, x2, y2, x2+1, house)
        # 세로 이동
        if y2 + 1 < N and house[y2+1][x2] == 0:
            dfs(y2, x2, y2+1, x2, house)
        # 대각선 이동
        if x2 + 1 < N and y2 + 1 < N and house[y2][x2+1] == 0 and house[y2+1][x2] == 0 and house[y2+1][x2+1] == 0:
            dfs(y2, x2, y2+1, x2+1, house)

    return

N = int(input())
house = [list(map(int, input().split())) for _ in range(N)]

answer = 0

dfs(0, 0, 0, 1, house)

print(answer)