def split_file(file):
    head, number, tail = "", "", ""
    
    i = 0
    while i < len(file) and not file[i].isdigit():
        head += file[i]
        i += 1
        
    while i < len(file) and file[i].isdigit():
        number += file[i]
        i += 1
    
    tail = file[i:]
    
    return head, int(number), tail
        
def solution(files):
    answer = []
    parsed = []
    
    for file in files:
        head, number, tail = split_file(file)
        parsed.append((head, number, file))
    
    parsed.sort(key=lambda x: (x[0].lower(), x[1]))
    
    for elem in parsed:
        answer.append(elem[2])
    
    return answer
