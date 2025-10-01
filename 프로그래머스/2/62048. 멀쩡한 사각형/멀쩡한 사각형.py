import math

def solution(w, h):
    # 최대공약수
    g = math.gcd(w, h)
    # 잘려 나가는 칸 개수
    cut = w + h - g
    # 멀쩡한 칸 개수
    return w * h - cut
