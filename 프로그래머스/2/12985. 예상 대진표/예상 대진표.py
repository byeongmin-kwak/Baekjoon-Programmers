import math

def solution(n,a,b):
    answer = 0

    while True:
        a = math.ceil(a / 2)
        b = math.ceil(b / 2)
        
        answer += 1
        
        if a == b:
            return answer
    
    return answer