function solution(s) {
    let answer = '';
    
    arr = s.split(' ');
    
    minValue = Math.min(...arr);
    maxValue = Math.max(...arr);
    
    answer = minValue + ' ' + maxValue;
    
    return answer;
}