def solution(s):
    answer = []
    
    cnt = 0
    zero = 0
    
    while s != "1":
        tmp = ""
        for n in s:
            if n == "1":
                tmp += "1"
            else:
                zero += 1
        
        s = bin(len(tmp))[2:]
        cnt += 1
    
    answer = [cnt, zero]
    
    return answer