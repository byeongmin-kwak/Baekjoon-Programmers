def cnt_brown(w, h):
    return w*2 + (h-2)*2

def solution(brown, yellow):
    answer = []
    
    for i in range(1, int(yellow**0.5)+1):
        if yellow % i != 0:
            continue
        
        h = i + 2
        w = yellow / i + 2
        
        if cnt_brown(w, h) == brown:
            answer.append(w)
            answer.append(h)
            break

    return answer