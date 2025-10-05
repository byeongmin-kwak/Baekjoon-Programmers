arr = map(int, input().split())

answer = 0

total = 0
for elem in arr:
    total += elem**2
    
answer = total % 10

print(answer)