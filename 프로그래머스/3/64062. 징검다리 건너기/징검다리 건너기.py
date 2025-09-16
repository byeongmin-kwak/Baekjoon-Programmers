from collections import deque

def solution(stones, k):
    answer = float('inf')
    dq = deque()  # 인덱스를 저장

    for i in range(len(stones)):
        # 윈도우 벗어난 값 제거
        while dq and dq[0] <= i - k:
            dq.popleft()
        
        # 현재 값보다 작은 애들은 쓸모없으니 제거
        while dq and stones[dq[-1]] <= stones[i]:
            dq.pop()
        
        dq.append(i)
        
        # 윈도우가 k 크기에 도달하면 최댓값 후보 확인
        if i >= k-1:
            answer = min(answer, stones[dq[0]])
    
    return answer
