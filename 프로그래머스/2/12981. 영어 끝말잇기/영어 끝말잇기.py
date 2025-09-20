def solution(n, words):
    answer = []

    dict = {}
    
    dict[words[0]] = True
    for i in range(1, len(words)):
        if words[i][0] != words[i-1][-1]:
            num = (i+1) % n
            if num == 0:
                num = n
                turn = (i+1) // n
            else:
                turn = (i+1) // n + 1
            answer = [num, turn]
            break
        
        if words[i] not in dict:
            dict[words[i]] = True
        else:
            num = (i+1) % n
            if num == 0:
                num = n
                turn = (i+1) // n
            else:
                turn = (i+1) // n + 1
            answer = [num, turn]
            break
            
    if not answer:
        answer = [0, 0]
    return answer