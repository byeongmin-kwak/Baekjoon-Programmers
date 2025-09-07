def solution(msg):
    answer = []
    
    dictionary = {}
    
    for i in range(26):
        dictionary[chr(ord('A') + i)] = i + 1
        
    i = 0
    while i < len(msg):
        word = msg[i]
        
        for j in range(i+1, len(msg)):
            tmp = word+msg[j]
            if tmp in dictionary:
                word = tmp
                i += 1
            else:
                dictionary[tmp] = len(dictionary.items())+1
                break
            
        answer.append(dictionary[word])
        i += 1
    
    return answer