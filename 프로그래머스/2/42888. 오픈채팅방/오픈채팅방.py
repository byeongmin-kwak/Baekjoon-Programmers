def solution(record):
    answer = []
    
    dic = {}
    
    for elem in record:
        elem = elem.split(" ")
        command = elem[0]
        id = elem[1]
        if len(elem) == 3:
            name = elem[2]
        
        if command == "Enter" or command == "Change":
            dic[id] = name
            
    for elem in record:
        elem = elem.split(" ")
        command = elem[0]
        id = elem[1]
        if len(elem) == 3:
            name = elem[2]
            
        if command == "Enter":
            if id in dic:
                s = dic[id] + "님이 들어왔습니다."
            else:
                s = name + "님이 들어왔습니다."
            answer.append(s)
        elif command == "Leave":
            if id in dic:
                s = dic[id] + "님이 나갔습니다."
            else:
                s = name + "님이 나갔습니다."
            answer.append(s)
        
    return answer