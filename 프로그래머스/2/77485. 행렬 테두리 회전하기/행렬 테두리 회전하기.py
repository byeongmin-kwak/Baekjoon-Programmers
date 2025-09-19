def solution(rows, columns, queries):
    # 행렬 초기화 (y=row, x=col)
    matrix = [[y * columns + x + 1 for x in range(columns)] for y in range(rows)]
    answer = []

    for y1, x1, y2, x2 in queries:
        y1, x1, y2, x2 = y1-1, x1-1, y2-1, x2-1  # 0-based index

        prev = matrix[y1][x1]
        min_val = prev

        # 위쪽
        for x in range(x1+1, x2+1):
            matrix[y1][x], prev = prev, matrix[y1][x]
            min_val = min(min_val, prev)

        # 오른쪽
        for y in range(y1+1, y2+1):
            matrix[y][x2], prev = prev, matrix[y][x2]
            min_val = min(min_val, prev)

        # 아래쪽
        for x in range(x2-1, x1-1, -1):
            matrix[y2][x], prev = prev, matrix[y2][x]
            min_val = min(min_val, prev)

        # 왼쪽
        for y in range(y2-1, y1-1, -1):
            matrix[y][x1], prev = prev, matrix[y][x1]
            min_val = min(min_val, prev)

        answer.append(min_val)

    return answer
