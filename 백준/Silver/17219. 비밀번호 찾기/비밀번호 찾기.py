import sys
input = sys.stdin.readline

N, M = map(int, input().split())

address_password = {}

for _ in range(N):
    address, password = input().split()
    address_password[address] = password
    
for _ in range(M):
    address = input().strip()
    print(address_password[address])