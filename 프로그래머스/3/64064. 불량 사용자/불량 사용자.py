def check(a, b):
    if len(a) != len(b):
        return False
    
    for i in range(len(a)):
        if (b[i] == '*'):
            continue
        if (a[i] != b[i]):
            return False
    
    return True

def dfs(user_id, banned_id, visited, lst, s):
    if len(lst) == len(banned_id):
        s.add(frozenset(lst))
        return

    banned = banned_id[len(lst)]
    
    for i in range(len(user_id)):
        if not visited[i] and check(user_id[i], banned):
            visited[i] = True
            lst.append(user_id[i])
            dfs(user_id, banned_id, visited, lst, s)
            lst.pop()
            visited[i] = False
                        
    return

def solution(user_id, banned_id):
    answer = 0
    
    visited = [False] * len(user_id)
    s = set()
    dfs(user_id, banned_id, visited, [], s)
    
    answer = len(s)   
    
    return answer