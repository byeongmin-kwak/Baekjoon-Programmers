def solution(n):
    digits = []
    while n > 0:
        if n % 3 == 0:
            digits.append('4')
            n = n // 3 - 1
        elif n % 3 == 1:
            digits.append('1')
            n //= 3
        else: 
            digits.append('2')
            n //= 3
    return ''.join(reversed(digits))
