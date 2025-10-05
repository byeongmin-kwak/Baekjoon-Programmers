L = int(input())
s = input()

answer = 0

for i in range(len(s)):
    answer += (ord(s[i])-96) * (31**i) % 1234567891
    
print(answer % 1234567891)