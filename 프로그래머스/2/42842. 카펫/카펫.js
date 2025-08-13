function solution(brown, yellow) {
    let answer = [];
    
    for (let x = 1; x <= Math.sqrt(yellow); x++) {
        y = yellow / x;
        
        if (((x+2)*2 + y*2) === brown) {
            answer.push(y+2);
            answer.push(x+2);
        }
    }
    return answer;
}