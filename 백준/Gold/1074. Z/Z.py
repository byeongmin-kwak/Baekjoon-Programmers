def solve(N, r, c):
    if N == 0:
        return 0
    
    half = 2 ** (N - 1)
    
    if r < half and c < half:
        return solve(N - 1, r, c)
    elif r < half and c >= half:
        return half * half + solve(N - 1, r, c - half)
    elif r >= half and c < half:
        return 2 * half * half + solve(N - 1, r - half, c)
    else:
        return 3 * half * half + solve(N - 1, r - half, c - half)


N, r, c = map(int, input().split())

print(solve(N, r, c))
