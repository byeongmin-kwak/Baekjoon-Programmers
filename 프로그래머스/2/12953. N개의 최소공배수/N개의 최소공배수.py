import math    

def solution(arr):
    answer = 0
    
    if len(arr) == 1:
        return arr[0]
    
    tmp = arr[0]
    for i in range(1, len(arr)):
        tmp = math.lcm(tmp, arr[i])
    
    answer = tmp
    
    return answer