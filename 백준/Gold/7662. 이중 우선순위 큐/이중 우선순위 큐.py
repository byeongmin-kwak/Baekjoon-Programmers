import sys, heapq
input = sys.stdin.readline

T = int(input())

while T > 0:
    k = int(input())
    
    min_heap = []
    max_heap = []
    visited = [False] * k
    
    for i in range(k):
        op, n = input().split()
        n = int(n)
        
        if op == 'I':
            heapq.heappush(min_heap, (n, i))
            heapq.heappush(max_heap, (-n, i))
            visited[i] = True
        else:
            if n == 1:
                while max_heap and not visited[max_heap[0][1]]:
                    heapq.heappop(max_heap)
                if max_heap:
                    visited[max_heap[0][1]] = False
                    heapq.heappop(max_heap)
            else:
                if min_heap:
                    while min_heap and not visited[min_heap[0][1]]:
                        heapq.heappop(min_heap)
                    if min_heap:
                        visited[min_heap[0][1]] = False
                        heapq.heappop(min_heap)
    
    while min_heap and not visited[min_heap[0][1]]:
        heapq.heappop(min_heap)
    while max_heap and not visited[max_heap[0][1]]:
        heapq.heappop(max_heap)
    
    if not min_heap or not max_heap:
        print("EMPTY")
    else:
        print(-max_heap[0][0], min_heap[0][0])
    
    T -= 1