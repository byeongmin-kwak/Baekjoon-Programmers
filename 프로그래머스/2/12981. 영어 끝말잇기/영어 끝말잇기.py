def solution(n, words):
    # set 이용 체크
    # 실패하는 시점에 누가 몇번째인지 구하기
    
    s = {words[0]}
    
    for i in range(1, len(words)):
        cur = words[i]
        prev = words[i-1]
        
        if cur[0] != prev[-1] or cur in s:
            person = (i % n) + 1
            turn = (i // n) + 1
            return [person, turn]
        
        s.add(cur)
        
    return [0,0]