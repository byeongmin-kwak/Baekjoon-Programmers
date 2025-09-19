def solution(s):
    answer = True
    
    open = 0
    for elem in s:
        if elem == '(':
            open += 1
        else:
            open -= 1
            if open < 0:
                return False
    if open > 0:
        return False

    return answer