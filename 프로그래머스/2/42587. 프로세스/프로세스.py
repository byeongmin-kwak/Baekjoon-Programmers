from collections import deque

def solution(priorities, location):
    queue = deque([(p, i) for i, p in enumerate(priorities)])  
    answer = 0

    while queue:
        current = queue.popleft() 
        if any(current[0] < other[0] for other in queue):
            queue.append(current) 
        else:
            answer += 1 
            if current[1] == location: 
                break  

    return answer
