import math

def solution(n, stations, w):
    answer = 0

    coverage = w*2+1
    prev = 0
    
    for station in stations:
        gap = station-w-prev-1
        if gap > 0:
            answer += math.ceil(gap / coverage)
        prev = station+w
    
    if prev < n:
        gap = n - prev
        answer += math.ceil(gap / coverage)

    return answer