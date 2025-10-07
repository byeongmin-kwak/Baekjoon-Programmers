s = input()
answer = 0
tmp = ''
minus = False

for i in range(len(s)):
    if s[i] != '+' and s[i] != '-':
        tmp += s[i]
    else:
        if minus:
            answer -= int(tmp)
            tmp = ''
            continue
        else:
            answer += int(tmp)
            tmp = ''
        
        if s[i] == '-':
            minus = True
    
if tmp:
    if minus:
        answer -= int(tmp)
    else:
        answer += int(tmp)
    
print(answer)