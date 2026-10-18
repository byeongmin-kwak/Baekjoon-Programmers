from collections import Counter

def solution(k, tangerine):
    answer = 0
    
    cnt = sorted(Counter(tangerine).values(), reverse=True)
    
    for c in cnt:
        answer += 1
        k -= c
        if k <= 0:
            break
    
    return answer