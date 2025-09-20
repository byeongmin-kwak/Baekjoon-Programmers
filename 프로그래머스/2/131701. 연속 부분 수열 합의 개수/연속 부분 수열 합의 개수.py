def solution(elements):
    n = len(elements)
    s = set()
    
    # 원형 배열 처리: 배열을 두 번 이어 붙이기
    arr = elements * 2
    
    # 1~n 길이의 연속 부분 수열
    for length in range(1, n+1):
        total = sum(arr[:length])  # 처음 합
        s.add(total)
        
        # 슬라이딩 윈도우로 합 계산
        for start in range(1, n):
            total = total - arr[start-1] + arr[start+length-1]
            s.add(total)
    
    return len(s)
