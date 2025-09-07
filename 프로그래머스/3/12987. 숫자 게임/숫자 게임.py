def solution(A, B):
    answer = 0
    
    A.sort()
    B.sort()
    
    left = 0
    right = len(B)-1
    
    while left <= right:
        if A[-1] < B[right]:
            right -= 1
            answer += 1
        else:
            left += 1
        A.pop()
    
    return answer