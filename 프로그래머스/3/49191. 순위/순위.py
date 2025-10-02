def solution(n, results):
    # 승패 기록 (그래프)
    graph = [[0] * (n+1) for _ in range(n+1)]

    for a, b in results:
        graph[a][b] = 1   # a가 b를 이김
        graph[b][a] = -1  # b는 a에게 짐

    # 플로이드-와샬: 간접 승패 관계 채우기
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if graph[i][k] == 1 and graph[k][j] == 1:
                    graph[i][j] = 1
                    graph[j][i] = -1
                if graph[i][k] == -1 and graph[k][j] == -1:
                    graph[i][j] = -1
                    graph[j][i] = 1

    answer = 0
    # 각 선수별로 승패가 n-1명과 다 정해져 있으면 순위 확정
    for i in range(1, n+1):
        count = 0
        for j in range(1, n+1):
            if graph[i][j] != 0:
                count += 1
        if count == n-1:
            answer += 1

    return answer
