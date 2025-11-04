from collections import deque

def solution(x, y, n):
    answer = 0
    
    if x == y:
        return 0
    
    visited = [False] * 1000000
    
    q = deque()
    q.append((x, 0))
    visited[x] = True
    
    while q:
        current, cnt = q.popleft()
                
        tmp = current + n
        if tmp == y:
            return cnt+1
        if tmp < y and not visited[tmp]:
            q.append((tmp, cnt+1))
            visited[tmp] = True
        
        tmp = current * 2
        if tmp == y:
            return cnt+1
        if tmp < y and not visited[tmp]:
            q.append((tmp, cnt+1))
            visited[tmp] = True
        
        tmp = current * 3
        if tmp == y:
            return cnt+1
        if tmp < y and not visited[tmp]:
            q.append((tmp, cnt+1))
            visited[tmp] = True
            
    return -1