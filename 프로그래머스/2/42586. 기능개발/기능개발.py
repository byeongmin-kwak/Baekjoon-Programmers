import math

def solution(progresses, speeds):
    answer = []
    
    i = 0
    while i < len(progresses):
        day = math.ceil((100-progresses[i]) / speeds[i])
        total = 1
        i += 1
        
        while i < len(progresses) and math.ceil((100 - progresses[i]) / speeds[i]) <= day:
            total += 1
            i += 1
        
        answer.append(total)
    
    return answer