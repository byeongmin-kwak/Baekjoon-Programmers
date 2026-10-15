def solution(n):
    # 마지막 수는 자동 추가
    answer = 1
    
    start = 1
    end = 1
    sum = 1
    
    while start <= n/2:
        # sum이 n보다 작으면 end++, sum+end
        if sum < n:
            end += 1
            sum += end
        # sum이 n보다 크면 sum-start, start++
        elif sum > n:
            sum -= start
            start += 1
        # sum이 n일 경우 answer++, sum-start, start++
        else:
            answer += 1
            sum -= start
            start += 1
            
    return answer