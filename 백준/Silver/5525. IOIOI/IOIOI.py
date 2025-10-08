N = int(input())
M = int(input())
S = input()

# IOI의 길이 세기 -> ans += 길이-N+1

answer = 0

P = [0] * (M + 1)

for i in range(2, M):
    if S[i] == 'I' and S[i - 1] == 'O' and S[i - 2] == 'I':
        P[i] = P[i - 2] + 1
        if P[i] >= N:
            answer += 1
            
print(answer)