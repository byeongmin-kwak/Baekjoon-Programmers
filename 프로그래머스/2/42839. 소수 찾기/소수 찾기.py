def check(number):
    if number < 2:
        return False
    
    for i in range(2, int(number**0.5)+1):
        if number % i == 0:
            return False
    
    return True
    
def dfs(numbers, number, s, visited):
    if number:
        if number[0] == '0':
            return
        if check(int(number)):
            s.add(int(number))
        
    if len(number) >= len(numbers):
        return
    
    for i in range(len(numbers)):
        if not visited[i]:
            visited[i] = True
            dfs(numbers, number+numbers[i], s, visited)
            visited[i] = False
    
    return

def solution(numbers):
    s = set()
    
    numbers = list(numbers)
    
    visited = [False] * len(numbers)
    dfs(numbers, '', s, visited)
    
    answer = len(s)
    
    return answer