function solution(want, number, discount) {
    let answer = 0;
    
    let start = 0, end = 9;
    while (end <= discount.length-1) {
        let checkNumber = new Array(number.length).fill(0);
        
        for (let i = start; i <= end; i++) {
            for (let j = 0; j < want.length; j++) {
                if (discount[i] === want[j]) {
                    checkNumber[j]++;
                }
            }
        }
                
        let flag = true;
        for (let i = 0; i < checkNumber.length; i++) {
            if (checkNumber[i] < number[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            answer++;
        }
        start++;
        end++;        
    }
    
    return answer;
}