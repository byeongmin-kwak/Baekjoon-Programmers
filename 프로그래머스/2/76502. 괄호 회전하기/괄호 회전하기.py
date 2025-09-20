from collections import deque

def check(deq):
    
    stack = []
    
    for elem in deq:
        if elem == ']':
            if stack and stack[-1] == '[':
                stack.pop()
            else:
                return False
        elif elem == '}':
            if stack and stack[-1] == '{':
                stack.pop()
            else:
                return False
        elif elem == ')':
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                return False
        else:
            stack.append(elem)
            
    if stack:
        return False
    else:
        return True
    

def solution(s):
    answer = 0
    
    deq = deque()
    
    for i in range(len(s)):
        deq.append(s[i])
        
    
    if check(deq):
            answer += 1
    for i in range(len(deq)-1):
        deq.append(deq.popleft())
        if check(deq):
            answer += 1
    
    return answer