def draw_star(n):
    if n == 3:
        return ["  *  ", " * * ", "*****"]

    stars = draw_star(n // 2)
    arr = []

    # 위쪽 삼각형
    for line in stars:
        arr.append(" " * (n // 2) + line + " " * (n // 2))
    # 아래쪽 두 삼각형
    for line in stars:
        arr.append(line + " " + line)
    return arr


N = int(input())
print("\n".join(draw_star(N)))