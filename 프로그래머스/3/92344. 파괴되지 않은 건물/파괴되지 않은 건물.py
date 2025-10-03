def solution(board, skill):
    n, m = len(board), len(board[0])
    diff = [[0] * (m+1) for _ in range(n+1)]
    
    # 1. skill 적용 (차이 배열에 기록)
    for type_, r1, c1, r2, c2, degree in skill:
        if type_ == 1:   # 공격
            degree = -degree
        else:            # 회복
            degree = degree
        
        diff[r1][c1] += degree
        diff[r1][c2+1] -= degree
        diff[r2+1][c1] -= degree
        diff[r2+1][c2+1] += degree

    # 2. 행 기준 누적합
    for i in range(n):
        for j in range(1, m):
            diff[i][j] += diff[i][j-1]

    # 3. 열 기준 누적합
    for j in range(m):
        for i in range(1, n):
            diff[i][j] += diff[i-1][j]

    # 4. 원래 board에 diff 적용 후 살아남은 건물 카운트
    answer = 0
    for i in range(n):
        for j in range(m):
            if board[i][j] + diff[i][j] > 0:
                answer += 1
    
    return answer
