def solution(number, k):
    answer = ''
    
    stack = []
    
    for n in number:
        
        while stack and k > 0 and stack[-1] < n:
            stack.pop()
            k -= 1
            
        stack.append(n)
        
    while k > 0:
        stack.pop()
        k -= 1
    
    answer = ''.join(stack)
    
    return answer