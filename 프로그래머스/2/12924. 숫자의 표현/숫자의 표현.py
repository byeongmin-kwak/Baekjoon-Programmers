def solution(n):
    answer = 1
    left, right = 1, 1
    total = 1
    
    while left <= n // 2:
        if total == n:
            answer += 1
        
        if total >= n:
            total -= left
            left += 1
        else:
            right += 1
            total += right
    
    return answer
