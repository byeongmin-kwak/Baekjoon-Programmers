from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer = 0
    time = 0
    que = deque()
    
    while truck_weights or que:
        time += 1
        
        if que and que[0][1] >= bridge_length:
            que.popleft()
    
        que = deque((w, t+1) for w, t in que)
        
        if truck_weights and sum(w for w, t in que) + truck_weights[0] <= weight:
            que.append((truck_weights.pop(0), 1))
        
    answer = time
    
    return time