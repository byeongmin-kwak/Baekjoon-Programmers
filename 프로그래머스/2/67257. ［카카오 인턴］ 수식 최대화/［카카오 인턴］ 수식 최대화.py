def dfs(arr, current, result, visited):
    if len(current) == len(arr):
        result.append(current[:])
        return
        
    for i in range(len(arr)):
        if not visited[i]:
            visited[i] = True
            current.append(arr[i])
            dfs(arr, current, result, visited)
            current.pop()
            visited[i] = False
    return

def calc(tokens, op_order):
    t = tokens[:]
    for op in op_order:
        stack = []
        i = 0
        while i < len(t):
            if t[i] == op:
                a = int(stack.pop())
                b = int(t[i+1])
                if op == '+':
                    stack.append(a + b)
                elif op == '-':
                    stack.append(a - b)
                else:  # '*'
                    stack.append(a * b)
                i += 2
            else:
                stack.append(int(t[i]) if t[i].isdigit() else t[i])
                i += 1
        t = [str(x) for x in stack]
    return abs(int(t[0]))

def solution(expression):
    # 1. 연산자 종류 확인
    arr = []
    for op in '+-*':
        if op in expression:
            arr.append(op)
    
    # 2. 우선순위 순열 생성
    result = []
    visited = [False] * len(arr)
    dfs(arr, [], result, visited)
    
    # 3. 숫자와 연산자로 나누기
    tokens = []
    num = ""
    for char in expression:
        if char in '+-*':
            tokens.append(num)
            tokens.append(char)
            num = ""
        else:
            num += char
    tokens.append(num)
    
    # 4. 최대값 계산
    answer = 0
    for op_order in result:
        answer = max(answer, calc(tokens, op_order))
    
    return answer
