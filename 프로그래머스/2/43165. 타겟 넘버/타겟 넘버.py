answer = 0

def dfs(numbers, target, currentSum, depth):
    global answer
    if (depth == len(numbers)):
        if (currentSum == target):
            answer += 1
        return
    
    dfs(numbers, target, currentSum+numbers[depth], depth+1)
    dfs(numbers, target, currentSum-numbers[depth], depth+1)
    
    return

def solution(numbers, target):
    
    
    dfs(numbers, target, 0, 0)
    
    return answer