import heapq

def solution(jobs):
    answer = 0
    
    jobs.sort()
    pq = []
    
    total = 0
    i = 0
    time = 0
    
    while i < len(jobs) or pq:
        
        while i < len(jobs) and jobs[i][0] <= time:
            heapq.heappush(pq, (jobs[i][1], jobs[i][0]))
            i += 1
        
        if pq:
            job = heapq.heappop(pq)
            time += job[0]
            total += time - job[1]
        else:
            time = jobs[i][0]
            
    answer = total // len(jobs)
    return answer