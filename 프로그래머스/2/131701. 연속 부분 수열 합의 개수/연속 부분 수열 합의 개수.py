def solution(elements):
    answer = 0
    
    elements2 = elements + elements
    s = set()
    
    for i in range(len(elements)):
        cur_sum = 0
        for j in range(len(elements)):
            cur_sum += elements2[i + j]
            s.add(cur_sum)
    
    answer = len(s)
    
    return answer