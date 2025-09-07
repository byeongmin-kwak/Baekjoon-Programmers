def solution(n, s):
    
    average = s // n
    
    if n > s:
        return [-1]
    
    answer = [average] * n
    
    for i in range(s%n):
        answer[-1-i] += 1
    
    return answer