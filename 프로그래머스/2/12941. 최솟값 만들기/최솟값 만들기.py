def solution(A,B):
    answer = float('inf')

    A.sort()
    B.sort()
    
    sum = 0
    for i in range(len(A)):
        sum += A[i]*B[len(B)-i-1]
    answer = min(answer, sum)

    return answer