from collections import Counter

def solution(k, tangerine):
    answer = 0
    
    # 귤 크기별 개수 세기
    counter = Counter(tangerine)
    
    # 개수 기준으로 내림차순 정렬
    sorted_counts = sorted(counter.values(), reverse=True)
    
    # 많이 나온 귤부터 담기
    total = 0
    for cnt in sorted_counts:
        total += cnt
        answer += 1
        if total >= k:
            break
    
    return answer
