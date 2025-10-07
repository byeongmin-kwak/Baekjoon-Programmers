def solve(arr, y, x, size, answer):
    if size == 1:
        answer[arr[y][x]] += 1
        return
    
    first = arr[y][x]
    for i in range(y, y + size):
        for j in range(x, x + size):
            if arr[i][j] != first:  
                half = size // 2
                solve(arr, y, x, half, answer)
                solve(arr, y, x + half, half, answer)
                solve(arr, y + half, x, half, answer)
                solve(arr, y + half, x + half, half, answer)
                return
            
    answer[first] += 1
    return 

N = int(input())

arr = [[] for _ in range(N)]

for i in range(N):
    arr[i] = list(map(int, input().split()))
    
answer = [0, 0]

solve(arr, 0, 0, N, answer)


print(answer[0])
print(answer[1])