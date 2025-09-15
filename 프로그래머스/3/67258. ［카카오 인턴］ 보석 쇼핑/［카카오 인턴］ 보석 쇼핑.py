def solution(gems):
    answer = [1, len(gems)]
    
    s = set()
    d = {}
    
    for elem in gems:
        d[elem] = 0
    
    start = 0
    end = 0
    minimum = len(d)
    s.add(gems[0])
    d[gems[0]] += 1
    
    while start <= end and start < len(gems) and end < len(gems):
        # print(len(s), minimum, start, end)
        if len(s) == minimum and (end-start) < answer[1]-answer[0]:
            answer[0] = start+1
            answer[1] = end+1
            
        if len(s) == minimum and d[gems[start]] > 1:
            d[gems[start]] -= 1
            start += 1
        else:
            end += 1
            if end == len(gems):
                break
            d[gems[end]] += 1
            s.add(gems[end])
            
    return answer