from itertools import combinations

N, M = map(int, input().split())

result = list(combinations( range(1, N + 1), M))

for comb in result:
    print(' '.join(map(str, comb)))
    