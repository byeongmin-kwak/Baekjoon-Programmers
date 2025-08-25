function solution(s) {
    let answer = 0;
    
    
    for (let i = 0; i < s.length; i++) {
        let stack = [];
        
        let newS = s.substr(i);
        newS += s.substr(0, i);
        
        let flag = true;
        for (let j = 0; j < newS.length; j++) {
            if (newS[j] === '(' || newS[j] === '{' || newS[j] === '[') {
                stack.push(newS[j]);
            }
            else {
                if (newS[j] === ')' && stack[stack.length-1] === '(') {
                    stack.pop();
                }
                else if (newS[j] === '}' && stack[stack.length-1] === '{') {
                    stack.pop();
                }
                else if (newS[j] === ']' && stack[stack.length-1] === '[') {
                    stack.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
        
        if (stack.length === 0 && flag) {
            answer++;
        }
    }
    
    
    return answer;
}