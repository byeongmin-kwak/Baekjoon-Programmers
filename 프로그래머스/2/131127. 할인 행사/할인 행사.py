def check(want, number, dict):
    
    for i in range(len(want)):
        if want[i] not in dict or dict[want[i]] < number[i]:
            return False
    
    return True
    

def solution(want, number, discount):
    answer = 0
    
    dict = {}
    
    for i in range(10):
        if discount[i] not in dict:
            dict[discount[i]] = 1
        else:
            dict[discount[i]] += 1
            
    if check(want, number, dict):
        answer += 1
    
    for i in range(10, len(discount)):        
        dict[discount[i-10]] -= 1
        
        if discount[i] in dict:
            dict[discount[i]] += 1
        else:
            dict[discount[i]] = 1
            
        if check(want, number, dict):
            answer += 1
        
        
    return answer