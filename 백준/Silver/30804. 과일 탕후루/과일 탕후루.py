N = int(input())
fruits = list(map(int, input().split()))

left, right = 0, 0
answer = 0
count = {}
type = 0

while right < N:
    if fruits[right] not in count or count[fruits[right]] == 0:
        type += 1
        count[fruits[right]] = 1
    else:
        count[fruits[right]] += 1
    
    while type > 2:
        count[fruits[left]] -= 1
        if count[fruits[left]] == 0:
            type -= 1
        left += 1
    answer = max(answer, right - left + 1)
    right += 1        

print(answer)