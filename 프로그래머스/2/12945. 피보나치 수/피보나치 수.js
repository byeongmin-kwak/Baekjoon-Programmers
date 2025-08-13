function solution(n) {
    let answer = 0;
    
    let a = 0, b = 1;
    for (let i = 2; i <= n; i++) {
        let tmp = (a + b) % 1234567;
        
        a = b;
        b = tmp;
    }
    
    answer = b;
    
    return answer;
}