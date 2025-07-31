function solution(dartResult) {
    var answer = 0;
    let point = 0;
    let points = [];
    
    for (let i = 0; i < dartResult.length; i++) {
        let current = dartResult[i];
        
        if (current >= '0' && current <= '9') {
            if (current == '1' && dartResult[i+1] == '0') {
                point = 10;
                i++;
            }
            else {
                point = current;
            }
        }
        
        else if (current == 'S') {
            points.push(Math.pow(point, 1));
        }
        else if (current == 'D') {
            points.push(Math.pow(point, 2));
        }
        else if (current == 'T') {
            points.push(Math.pow(point, 3));
        }
        
        else if (current == '#') {
            points[points.length-1] *= -1;
        }
        else if (current == '*') {
            points[points.length-1] *= 2;
            points[points.length-2] *= 2;
        }
    }
    
    for (let i = 0; i < points.length; i++) {
        answer += points[i];
    }
    
    return answer;
}