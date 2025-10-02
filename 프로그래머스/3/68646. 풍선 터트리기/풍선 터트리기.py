def solution(a):
    n = len(a)
    answer = 2 if n > 1 else 1  # 양 끝 풍선은 무조건 남음
    
    left_min = [0] * n
    right_min = [0] * n
    
    left_min[0] = a[0]
    for i in range(1, n):
        left_min[i] = min(left_min[i-1], a[i])
    
    right_min[-1] = a[-1]
    for i in range(n-2, -1, -1):
        right_min[i] = min(right_min[i+1], a[i])
    
    for i in range(1, n-1):
        if a[i] < left_min[i-1] or a[i] < right_min[i+1]:
            answer += 1
    
    return answer
