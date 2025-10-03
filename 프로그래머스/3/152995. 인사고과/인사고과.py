def solution(scores):
    # 완호 점수
    wanho_a, wanho_b = scores[0]
    wanho_sum = wanho_a + wanho_b

    # 정렬: a 내림차순, a 같으면 b 오름차순
    scores.sort(key=lambda x: (-x[0], x[1]))
    
    max_b = -1  # 지금까지 본 동료 평가 점수의 최대
    rank = 1    # 완호의 등수 (1등부터 시작)

    for a, b in scores:
        # 만약 a, b 모두 완호보다 높은 사람이면 완호 탈락
        if a > wanho_a and b > wanho_b:
            return -1

        # 동료평가 점수가 이전 최대값보다 커야 인센티브 가능성 있음
        if b >= max_b:
            # 이 사람이 완호보다 합이 크면 완호 등수 +1
            if a + b > wanho_sum:
                rank += 1
            # max_b 갱신
            max_b = b

    return rank
