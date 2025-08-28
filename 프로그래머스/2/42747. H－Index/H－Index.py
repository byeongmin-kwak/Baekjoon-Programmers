def solution(citations):
    answer = 0
    
    citations.sort()
    
    left = 0
    right = len(citations)
    
    while left <= right:
        mid = (left + right) // 2
        
        count = 0
        for elem in citations:
            if (elem >= mid):
                count += 1
        
        if count >= mid:
            answer = mid
            left = mid+1
        else:
            right = mid-1
    
    return answer