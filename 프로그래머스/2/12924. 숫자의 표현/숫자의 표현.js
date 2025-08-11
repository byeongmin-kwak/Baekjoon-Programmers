function solution(n) {
    let answer = 1;
    let start = 1, end = 1;
    let sum = 1;

    while (start <= n / 2) {
        if (sum === n) {
            answer++;
        }
        
        if (sum >= n) {
            sum -= start;
            start++;
        } else {
            end++;
            sum += end;
        }
    }

    return answer;
}
