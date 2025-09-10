def solve(arr, y, x, size):
    if size == 1:
        return
    
    n = arr[y][x]
    check = True
    for i in range(size):
        for j in range(size):
            if arr[y+i][x+j] != n:
                check = False
    
    if check:
        for i in range(size):
            for j in range(size):
                arr[y+i][x+j] = 3
        arr[y][x] = n
    else:
        solve(arr, y, x, size//2)
        solve(arr, y+size//2, x, size//2)
        solve(arr, y, x+size//2, size//2)
        solve(arr, y+size//2, x+size//2, size//2)

def solution(arr):
    answer = [0, 0]
    
    solve(arr, 0, 0, len(arr))
    
    
    for i in range(len(arr)):
        for j in range(len(arr)):
            if arr[i][j] == 0:
                answer[0] += 1
            elif arr[i][j] == 1:
                answer[1] += 1
    
    return answer