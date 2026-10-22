from collections import Counter

def solution(want, number, discount):
    
    answer = 0
    
    target = Counter(dict(zip(want, number)))
    
    # 2. 10일 연속 구간을 슬라이딩하며 비교
    # discount 길이가 N일 때, 10일 연속 구간의 시작점은 0부터 N - 10까지
    for i in range(len(discount) - 9):
        # 10일 간의 할인 품목을 Counter로 만들어 target과 직접 비교
        if Counter(discount[i:i + 10]) == target:
            answer += 1
            
    return answer