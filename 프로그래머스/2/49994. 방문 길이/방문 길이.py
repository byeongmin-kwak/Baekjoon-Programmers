def solution(dirs):
    answer = 0
    
    x, y = 5, 5
    visited = [[[[False]*11 for _ in range(11)] for _ in range(11)] for _ in range(11)]
    
    for command in dirs:
        ny, nx = y, x
        if (command == 'U'):
            ny += 1 
        elif (command == 'D'):
            ny -= 1
        elif (command == 'R'):
            nx += 1
        else:
            nx -= 1
        
        if ny >= 0 and ny <= 10 and nx >= 0 and nx <= 10:
            if not visited[y][x][ny][nx]:
                visited[y][x][ny][nx] = True
                visited[ny][nx][y][x] = True
                answer += 1
            y, x = ny, nx
    
    return answer