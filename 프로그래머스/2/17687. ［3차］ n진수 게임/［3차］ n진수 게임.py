def to_base(n, base):
    if n == 0:
        return "0"
    
    digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"  # 최대 36진수까지 가능
    res = ""
    
    while n > 0:
        n, remainder = divmod(n, base)
        res = digits[remainder] + res
    
    return res

def solution(n, t, m, p):
    answer = ''
    
    num = 0
    turn = 0
    flag = True
    while flag:
        newNum = to_base(num, n)
        
        for i in range(len(newNum)):
            turn += 1
            if turn % m == p or (m == p and turn % p == 0):
                answer += newNum[i]
                if len(answer) >= t:
                    flag = False
                    break
        
        num += 1
        
    return answer
