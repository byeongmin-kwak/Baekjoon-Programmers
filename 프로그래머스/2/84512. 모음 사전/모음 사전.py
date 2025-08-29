answer = -1
flag = False

def dfs(word, current, alphabet, depth):
    global answer, flag
    
    if flag or depth > 5:
        return
    
    answer+= 1
    if current == word:
        flag = True
        return
    
    for elem in alphabet:
        dfs(word, current+elem, alphabet, depth+1)
    
    return
    
def solution(word):
    
    alphabet = ['A', 'E', 'I', 'O', 'U']
    
    dfs(word, "", alphabet, 0)
    
    return answer