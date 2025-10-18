n = int(input())
paper = [[0] * 100 for _ in range(100)]  # 100x100 도화지

for _ in range(n):
    x, y = map(int, input().split())
    for i in range(x, x + 10):       # 가로 10칸
        for j in range(y, y + 10):   # 세로 10칸
            paper[i][j] = 1          # 색종이 영역 표시

area = sum(sum(row) for row in paper)

print(area)
