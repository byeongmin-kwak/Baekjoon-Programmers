def solution(brown, yellow):
    answer = []
    
    for yh in range(1, int(yellow**0.5)+1):
        if yellow % yh == 0:
            yw = yellow // yh

            if (brown == (yw+2)*2 + yh*2):
                answer = [yw+2, yh+2] 
                break

    return answer