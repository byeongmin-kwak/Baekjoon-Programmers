import math

N = int(input())
num = list(map(int, input().split()))
t, p = map(int, input().split())

answer_t = 0
answer_p1 = 0
answer_p2 = 0

for elem in num:
    answer_t += math.ceil(elem / t)
    
answer_p1 = N // p
answer_p2 = N % p

print(answer_t)
print(answer_p1, answer_p2)
