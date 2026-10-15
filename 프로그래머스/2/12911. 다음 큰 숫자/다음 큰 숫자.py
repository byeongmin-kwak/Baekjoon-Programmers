def solution(n):
    answer = 0
    
    # n 이후의 수 중 2진수로 변환했을 때 1의 개수가 같은 수
    cnt = bin(n)[2:].count('1')
    
    for i in range(n+1, 1000000):
        if cnt == bin(i)[2:].count('1'):
            answer = i
            break
    
    return answer