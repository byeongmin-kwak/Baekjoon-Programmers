import sys

N = int(input())

people = list(map(int, sys.stdin.readline().split()))

people.sort()

result = 0

for i in range(N):
    result += people[i]*(N-i)
    
print(result)