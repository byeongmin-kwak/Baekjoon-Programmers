from itertools import combinations
from collections import Counter

def solution(orders, course):
    answer = []
    for c in course:
        combos = []
        for order in orders:
            # 각 주문에서 c개 뽑기
            for comb in combinations(sorted(order), c):
                combos.append("".join(comb))
        counter = Counter(combos)
        
        if not counter:
            continue
        max_count = max(counter.values())
        if max_count >= 2:  # 최소 2명 이상이 주문한 메뉴만
            for menu, cnt in counter.items():
                if cnt == max_count:
                    answer.append(menu)
    
    return sorted(answer)
