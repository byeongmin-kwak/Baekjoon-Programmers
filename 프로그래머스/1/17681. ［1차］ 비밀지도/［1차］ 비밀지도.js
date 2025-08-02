function solution(n, arr1, arr2) {
    var answer = [];
    
    for (let i = 0; i < n; i++) {
        let binary = (arr1[i] | arr2[i]).toString(2).padStart(n, '0');   
        
        let line = '';
        for (let j = 0; j < n; j++) {
            line += binary[j] === '1' ? '#' : ' ';  
        }
        
        answer.push(line);
    }
    
    return answer;
}