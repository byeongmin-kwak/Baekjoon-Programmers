from collections import deque

def solution(n):
    answer = 1
    que = deque()
    total = 0
    
    if n < 3:
        return 1
    
    for i in range(1, n//2 + 2):
        total += i
        que.append(i)
        
        while total > n:
            total -= que.popleft()
        
        if total == n:
            answer += 1
    
    return answer
