def solution(n):
    answer = 0
    
    tmp = n+1
    cnt = bin(n).count('1')
    
    while True:
        if bin(tmp).count('1') == cnt:
            answer = tmp
            break
        tmp += 1
    
    return answer