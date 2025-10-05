import sys
input = sys.stdin.readline

n = int(input())
if n == 0:
    print(0)
    exit()

levels = [int(input()) for _ in range(n)]
levels.sort()

# 절사 범위 계산
tmp = int(n * 0.15 + 0.5)  # 0.5 이상이면 올림

# 절사 후 합계
total = sum(levels[tmp : n - tmp])

# 평균 계산 후 반올림
length = n - 2*tmp
average = int(total / length + 0.5)  # 0.5 이상 올림
print(average)
