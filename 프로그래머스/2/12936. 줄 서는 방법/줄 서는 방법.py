import math

def solution(n, k):
    numbers = list(range(1, n+1))  # 남은 숫자들
    answer = []

    k -= 1  # 0-based index로 맞추기

    for i in range(n, 0, -1):
        fact = math.factorial(i-1)
        idx = k // fact
        k %= fact

        answer.append(numbers.pop(idx))

    return answer
