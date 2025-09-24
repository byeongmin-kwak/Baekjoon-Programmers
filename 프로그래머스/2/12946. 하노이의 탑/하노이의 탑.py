def hanoi(n, start, to, other, answer):
    if n == 1:
        answer.append([start, to])
    else:
        hanoi(n-1, start, other, to, answer)
        answer.append([start, to])
        hanoi(n-1, other, to, start, answer)
    return

def solution(n):
    answer = []
    
    hanoi(n, 1, 3, 2, answer)
    
    return answer