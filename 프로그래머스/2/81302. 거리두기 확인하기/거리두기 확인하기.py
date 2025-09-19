def check(place, y, x):
    # 상하좌우 확인
    if (y-1 >= 0 and place[y-1][x] == 'P') or (x+1 < 5 and place[y][x+1] == 'P') or (y+1 < 5 and place[y+1][x] == 'P') or (x-1 >= 0 and place[y][x-1] == 'P'):
        return False
    
    # 대각선 확인
    if y-1 >= 0 and x-1 >= 0 and place[y-1][x-1] == 'P':
        if place[y-1][x] != 'X' or place[y][x-1] != 'X':
            return False
    if y-1 >= 0 and x+1 < 5 and place[y-1][x+1] == 'P':
        if place[y-1][x] != 'X' or place[y][x+1] != 'X':
            return False
    if y+1 < 5 and x+1 < 5 and place[y+1][x+1] == 'P':
        if place[y][x+1] != 'X' or place[y+1][x] != 'X':
            return False
    if y+1 < 5 and x-1 >= 0 and place[y+1][x-1] == 'P':
        if place[y][x-1] != 'X' or place[y+1][x] != 'X':
            return False
    
    # 2칸 상하좌우 확인
    if y-2 >= 0 and place[y-2][x] == 'P':
        if place[y-1][x] != 'X':
            return False
    if x+2 < 5 and place[y][x+2] == 'P':
        if place[y][x+1] != 'X':
            return False
    if y+2 < 5 and place[y+2][x] == 'P':
        if place[y+1][x] != 'X':
            return False
    if x-2 >= 0 and place[y][x-2] == 'P':
        if place[y][x-1] != 'X':
            return False
    
    return True

def solve(place):
    for y in range(5):
        for x in range(5):
            if place[y][x] == 'P':
                if not check(place, y, x):
                    return False
    
    return True

def solution(places):
    answer = []
    
    for place in places:
        if solve(place):
            answer.append(1)
        else:
            answer.append(0)
    
    return answer