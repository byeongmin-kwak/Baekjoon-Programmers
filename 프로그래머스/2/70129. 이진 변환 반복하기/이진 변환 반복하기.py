def solution(s):
    answer = []
    
    cnt = 0
    zero = 0
    
    tmp = 10
    while s != '1':
        cnt += 1
        # 0 개수 세기
        c = 0
        for i in s:
            if i == '0':
                zero += 1
            else:
                c += 1
        
        # 길이를 2진법으로 변경
        s = bin(c)[2:]
    
    answer.append(cnt)
    answer.append(zero)
    
    return answer