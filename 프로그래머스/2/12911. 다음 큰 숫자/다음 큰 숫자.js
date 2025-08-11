function solution(n) {
    let answer = 0;
    
    binaryN = n.toString(2);
    cnt = 0;
    for (let i = 0; i < binaryN.length; i++) {
        if (binaryN[i] === '1') {
            cnt++;
        }
    }
    
    for (let i = n+1; i <= 1000000; i++) {
        binaryI = i.toString(2);
        let cntI = 0;
        for (let j = 0; j < binaryI.length; j++) {
            if (binaryI[j] === '1') {
                cntI++;
            }
        }
        if (cnt === cntI) {
            answer = i;
            break;
        }
    }
    
    return answer;
}