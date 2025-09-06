import heapq

def solution(n, works):
    answer = 0
    
    heap = []
    
    for elem in works:
        heapq.heappush(heap, -elem)
        
    while n > 0:
        largest = -heapq.heappop(heap)  
        if largest > 0:
            largest -= 1
        heapq.heappush(heap, -largest) 
        n -= 1

    for elem in heap:
        answer += elem * elem
    
    return answer