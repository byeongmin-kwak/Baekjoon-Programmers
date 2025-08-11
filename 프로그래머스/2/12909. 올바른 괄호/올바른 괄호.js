function solution(s){
    let answer = true;

    let queue = [];
    
    for (let i = 0; i < s.length; i++) {
        if (s[i] == '(') {
            queue.push('(');
        }
        else {
            if (queue.length > 0) {
                queue.pop();
            }
            else {
                answer = false;
            }
        }
    }
    if (queue.length > 0) answer = false;

    return answer;
}