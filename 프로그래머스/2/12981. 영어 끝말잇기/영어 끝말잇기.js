function solution(n, words) {
    let answer = [0, 0];
    
    let map = new Map();
    map.set(words[0], 1);

    let number = 2;
    for (let i = 1; i < words.length; i++) {
        if (number === n+1) number = 1;
        
        // 앞 단어랑 다른 단어일때
        if (words[i][0] !== words[i-1][words[i-1].length-1]) {
            answer[0] = number;
            answer[1] = Math.floor(i / n) + 1;
            break;
        }
        
        // 이미 나왔던 단어일때
        if (map.has(words[i])) {
            answer[0] = number;
            answer[1] = Math.floor(i / n) + 1; 
            break;
        }
        
        map.set(words[i], 1);
        
        number++;
    }
    
    
    return answer;
}