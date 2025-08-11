function solution(s) {
    let answer = '';
    
    let arr = s.split(' ');
    
    let maxValue = Math.max(...arr);
    let minValue = Math.min(...arr);
    
    answer += minValue;
    answer += ' ';
    answer += maxValue;
    
    return answer;
}