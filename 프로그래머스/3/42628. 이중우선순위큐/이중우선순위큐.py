def solution(operations):
    heap = []
    
    for o in operations:
        if o[0] == "I":  # 삽입
            number = int(o[2:])
            heap.append(number)
        elif o == "D 1":  # 최댓값 삭제
            if heap:
                heap.remove(max(heap))
        elif o == "D -1":  # 최솟값 삭제
            if heap:
                heap.remove(min(heap))
    
    if not heap:
        return [0, 0]
    return [max(heap), min(heap)]
