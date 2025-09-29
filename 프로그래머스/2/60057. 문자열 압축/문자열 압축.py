def solve(n, s):
    result = ''
    i = 0
    while i < len(s):
        cnt = 1
        tmp = s[i:i+n]
        for j in range(i+n, len(s), n):
            if s[j:j+n] == tmp:
                cnt += 1
            else:
                break
        if cnt > 1:
            result += str(cnt) + tmp
        else:
            result += tmp
        
        i += n*cnt
    
    return len(result)

def solution(s):
    answer = float('inf')
    
    if len(s) == 1:
        return 1
    
    for i in range(1, len(s)//2+1):
        answer = min(answer, solve(i, s))
        
    return answer