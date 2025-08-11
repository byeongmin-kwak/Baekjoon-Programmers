function solution(s) {
    let answer = [0, 0];
    
    while (s !== "1") {
        
        let tmp = "";
        let cnt = 0;
        for (let i = 0; i < s.length; i++) {
            if (s[i] === "1") {
                tmp += "1";
            }
            else {
                cnt++;
            }
        }
        
        s = tmp.length.toString(2);
        answer[0]++ 
        answer[1] += cnt;
    }
    
    
    return answer;
}