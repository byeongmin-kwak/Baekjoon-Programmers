import sys
input = sys.stdin.readline

def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

def union(parent, a, b):
    ra = find(parent, a)
    rb = find(parent, b)
    if ra != rb:
        if ra < rb:
            parent[rb] = ra
        else:
            parent[ra] = rb

N, M = map(int, input().split())
truth_info = list(map(int, input().split()))
t = truth_info[0]
truth_people = truth_info[1:]  # 진실을 아는 사람들

parties = []
for _ in range(M):
    data = list(map(int, input().split()))
    cnt = data[0]
    ppl = data[1:]
    parties.append(ppl)
    
parent = [i for i in range(N + 1)]

# 1. 파티 참석자들끼리 union
for ppl in parties:
    for i in range(len(ppl) - 1):
        union(parent, ppl[i], ppl[i + 1])

# 2. 진실 아는 사람들을 하나의 그룹으로 묶기
if t > 0:
    base = truth_people[0]
    for person in truth_people[1:]:
        union(parent, base, person)

ans = 0
# 3. 각 파티마다 거짓말 가능한지 검사
for ppl in parties:
    can_lie = True
    for person in ppl:
        is_truth = False
        for tp in truth_people:
            if find(parent, person) == find(parent, tp):
                is_truth = True
                break
        if is_truth:
            can_lie = False
            break
    if can_lie:
        ans += 1

print(ans)
