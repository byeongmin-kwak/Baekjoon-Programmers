import heapq

def solution(scoville, K):
    answer = 0
    
    heap = []
    
    for elem in scoville:
        heapq.heappush(heap, elem)
    
    while heap[0] < K:
        scoville1 = heapq.heappop(heap)
        
        if heap:
            scoville2 = heapq.heappop(heap)
        else:
            return -1
        
        heapq.heappush(heap, scoville1+scoville2*2)
        
        answer += 1

    return answer