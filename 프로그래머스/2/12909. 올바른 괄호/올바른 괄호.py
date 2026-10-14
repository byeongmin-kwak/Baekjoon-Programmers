def solution(s):
    answer = True
    
    if len(s) % 2 != 0:
        return False
    
    cnt = 0
    
    for char in s:
        if char == '(':
            cnt += 1
        else:
            cnt -= 1
            
        if cnt < 0:
            return False
    
    return cnt == 0