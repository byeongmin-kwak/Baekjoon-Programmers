def solution(n, costs):
    # 부모 노드 찾기
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])  # 경로 압축
        return parent[x]

    # 두 집합 합치기
    def union(a, b):
        ra, rb = find(a), find(b)
        if ra != rb:
            parent[rb] = ra
            return True
        return False

    # 부모 초기화
    parent = [i for i in range(n)]

    # 비용 기준으로 간선 정렬
    costs.sort(key=lambda x: x[2])

    total_cost = 0
    edges_used = 0

    for a, b, c in costs:
        if union(a, b):   # 연결 안 돼 있으면 연결
            total_cost += c
            edges_used += 1
            if edges_used == n - 1:  # MST 완성
                break

    return total_cost
