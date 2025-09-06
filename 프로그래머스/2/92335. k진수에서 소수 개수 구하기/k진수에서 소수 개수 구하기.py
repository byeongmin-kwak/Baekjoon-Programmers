def conversion(n, k):
    result = ''
    
    while n > 0:
        result = str(n % k) + result
        n = n // k
    
    return result

def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def solution(n, k):
    answer = 0
    
    number = conversion(n, k)
    
    candidates = number.split('0')
    
    
    for elem in candidates:
        if elem and is_prime(int(elem)):
            answer += 1
    
    return answer