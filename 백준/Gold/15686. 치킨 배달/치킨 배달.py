from itertools import combinations

N, M = map(int, input().split())
city = [list(map(int, input().split())) for _ in range(N)]

houses = []
chickens = []

for y in range(N):
    for x in range(N):
        if city[y][x] == 1:
            houses.append((y, x))
        elif city[y][x] == 2:
            chickens.append((y, x))
            
min_distance = float('inf')

for selected in combinations(chickens, M):
    total_distance = 0
    for hy, hx in houses:
        dist = float('inf')
        for cy, cx in selected:
            dist = min(dist, abs(hy - cy) + abs(hx - cx))
        total_distance += dist
    min_distance = min(min_distance, total_distance)
    
print(min_distance)