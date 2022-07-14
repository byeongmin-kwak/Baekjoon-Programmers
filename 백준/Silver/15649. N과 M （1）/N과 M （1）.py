N, M = map(int, input().split())

current_stack=[]

def n_and_m(end, max_depth):
    for i in range(1, end+1):
        if i in current_stack:
            continue
        
        current_stack.append(i)
        
        if len(current_stack) == max_depth:
            print(*current_stack)
        else:
            n_and_m(end, max_depth)
        
        current_stack.pop()

n_and_m(N, M)