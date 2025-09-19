def solution(s):
    answer = -1

    stack = []
    
    for elem in s:
        if stack and elem == stack[-1]:
            stack.pop()
        else:
            stack.append(elem)
    
    if stack:
        answer = 0
    else:
        answer = 1
    
    return answer