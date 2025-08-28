def solution(s):
    answer = []
    
    s = s.lstrip('{').rstrip('}').split('},{')
    
    tupleLists = []
    for elem in s:
        tupleLists.append(list(map(int, elem.split(','))))
    
    tupleLists.sort(key=len)
    
    seen = set()
    
    for l in tupleLists:
        for num in l:
            if num not in seen:
                answer.append(num)
                seen.add(num)
    
    return answer